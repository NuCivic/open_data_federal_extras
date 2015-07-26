<?php

use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\MinkExtension\Context\MinkContext;
use Drupal\DrupalExtension\Context\DrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;
use Behat\Behat\Hook\Scope\BeforeStepScope;
use Behat\Behat\Hook\Scope\AfterStepScope;
use Behat\Behat\Hook\Scope\BeforeScenarioScope;
use Behat\Gherkin\Node\PyStringNode;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Tester\Exception\PendingException;

/**
 * Defines application features from the specific context.
 */
class FeatureContext extends RawDrupalContext implements SnippetAcceptingContext {

  /**
   * @Then I should see all of the POD fields
   */
  public function iShouldSeeAllOfThePodFields()
  {
    $podFields = array(
      'accessLevel' => 'Public Access Level',
      'bureauCodeUSG' => 'Bureau Code',
      'programCodeUSG ' => 'Program Code',
      'license' => 'License',
      'rights ' => 'Rights',
      'spatial' => 'Spatial',
      'temporal' => 'Temporal',
      'distribution ' => 'Distribution',
      'accrualPeriodicity' => 'Frequency',
      'conformsTo' => 'Data Standard',
      'dataQualityUSG' => 'Data Quality',
      'describedBy' => 'Data Dictionary',
      'describedByType' => 'Data Dictionary Type',
      'isPartOf' => 'Collection',
      //'issued' => 'Release Date',
      'language' => 'Language',
      'landingPage' => 'Homepage URL',
      'primaryITInvestmentUIIUSG' => 'Primary IT Investment UII',
      'systemOfRecordsUSG' => 'System of Records',
      'theme' => 'Category',
    );
    // Changes for DKAN field names.
    $podFields['references'] = "Related Content";
    $podFields['distribution'] = "Resources";
    // This is the "Created" date.
    unset($podFields['issued']);
    foreach ($podFields as $key => $fieldName) {
      $this->assertSession()->pageTextContains($fieldName);
    }
  }
  // Store pages to be referenced in an array.
  protected $pages = array();
  protected $groups = array();

  /**
   * Initializes context.
   *
   * Every scenario gets its own context instance.
   * You can also pass arbitrary arguments to the
   * context constructor through behat.yml.
   */
  public function __construct($parameters) {
    date_default_timezone_set('America/New_York');
    $this->params = !empty($parameters) ? $parameters : array();
  }

  /******************************
   * HOOKS
   ******************************/


  /** @AfterStep */
  public function debugStepsAfter(AfterStepScope $scope)
  {
    // Tests tagged with @debugEach will perform each step and wait for [ENTER] to proceed.
    if ($this->scenario->hasTag('debugEach')) {
      $env = $scope->getEnvironment();
      $drupalContext = $env->getContext('Drupal\DrupalExtension\Context\DrupalContext');
      $minkContext = $env->getContext('Drupal\DrupalExtension\Context\MinkContext');
      // Print the current URL.
      try {
        $minkContext->printCurrentUrl();
      }
      catch(Behat\Mink\Exception\DriverException $e) {
        print "No Url";
      }
      $drupalContext->iPutABreakpoint();
    }
  }

  /**
   * @BeforeStep
   */
  public function debugStepsBefore(BeforeStepScope $scope)
  {
    // Tests tagged with @debugBeforeEach will wait for [ENTER] before running each step.
    if ($this->scenario->hasTag('debugBeforeEach')) {
      $env = $scope->getEnvironment();
      $drupalContext = $env->getContext('Drupal\DrupalExtension\Context\DrupalContext');
      $drupalContext->iPutABreakpoint();
    }
  }

  /**
   * @BeforeScenario
   */
   public function registerScenario(BeforeScenarioScope $scope) {
     // Scenario not usually available to steps, so we do ourselves.
     // See issue
     $this->scenario = $scope->getScenario();
   }

  /****************************
   * HELPER FUNCTIONS
   ****************************/

  public function addPage($page) {
    $this->pages[$page['title']] = $page;
  }

  /*****************************
   * CUSTOM STEPS
   *****************************/

  /**
   * @Given pages:
   */
  public function addPages(TableNode $pagesTable) {
    foreach ($pagesTable as $pageHash) {
      // @todo Add some validation.
      $this->addPage($pageHash);
    }
  }

  /**
   * @Given I am on (the) :page page
   */
  public function iAmOnPage($page_title)
  {
    if (isset($this->pages[$page_title])) {
      $session = $this->getSession();
      $url = $this->pages[$page_title]['url'];
      $session->visit($this->locatePath($url));
      $code = $session->getStatusCode();

      if ($code < 200 || $code >= 300) {
        throw new Exception("Page $page_title ($url) visited, but it returned a non-2XX response code of $code.");
      }
    }
    else {
      throw new Exception("Page $page_title not found in the pages array, was it added?");
    }

  }

  /**
   * @When I search for :term
   */
  public function iSearchFor($term) {
    $session = $this->getSession();
    $search_form_id = '#dkan-sitewide-dataset-search-form--2';
    $search_form = $session->getPage()->findAll('css', $search_form_id);
    if (count($search_form) == 1) {
      $search_form = array_pop($search_form);
      $search_form->fillField("search", $term);
      $search_form->pressButton("edit-submit--2");
      $results = $session->getPage()->find("css", ".view-dkan-datasets");
      if (!isset($results)) {
        throw new Exception("Search results region not found on the page.");
      }
    }
    else if(count($search_form) > 1) {
      throw new Exception("More than one search form found on the page.");
    }
    else if(count($search_form) < 1) {
      throw new Exception("No search form with the id of found on the page.");
    }
  }

  /**
   * @Given groups:
   */
  public function addGroups(TableNode $groupsTable)
  {
    // Map readable field names to drupal field names.
    $field_map = array(
      'author' => 'author',
      'title' => 'title',
      'published' => 'published'
    );

    foreach ($groupsTable as $groupHash) {
      $node = new stdClass();
      $node->type = 'group';
      foreach($groupHash as $field => $value) {
        if(isset($field_map[$field])) {
          $drupal_field = $field_map[$field];
          $node->$drupal_field = $value;
        }
        else {
          throw new Exception(sprintf("Group field %s doesn't exist, or hasn't been mapped. See FeatureContext::addGroups for mappings.", $field));
        }
      }
      $created_node = $this->getDriver()->createNode($node);

      // Add the created node to the groups array.
      $this->groups[$created_node->nid] = $created_node;

      // Add the url to the page array for easy navigation.
      $this->addPage(array(
        'title' => $created_node->title,
        'url' => '/node/' . $created_node->nid
      ));
    }
  }

  /**
   * Creates multiple group memberships.
   *
   * Provide group membership data in the following format:
   *
   * | user  | group     | role on group        | membership status |
   * | Foo   | The Group | administrator member | Active            |
   *
   * @Given group memberships:
   */
  public function addGroupMemberships(TableNode $groupMembershipsTable)
  {
    foreach ($groupMembershipsTable->getHash() as $groupMembershipHash) {

      if (isset($groupMembershipHash['group']) && isset($groupMembershipHash['user'])) {

        $group = $this->getGroupByName($groupMembershipHash['group']);
        $user = user_load_by_name($groupMembershipHash['user']);

        // Add user to group with the proper group permissions and status
        if ($group && $user) {

          // Add the user to the group
          og_group("node", $group->nid, array(
            "entity type" => "user",
            "entity" => $user,
            "membership type" => OG_MEMBERSHIP_TYPE_DEFAULT,
            "state" => $this->getMembershipStatusByName($groupMembershipHash['membership status'])
          ));

          // Grant user roles
          $group_role = $this->getGroupRoleByName($groupMembershipHash['role on group']);
          og_role_grant("node", $group->nid, $user->uid, $group_role);

        } else {
          if (!$group) {
            throw new Exception(sprintf("No group was found with name %s.", $groupMembershipHash['group']));
          }
          if (!$user) {
            throw new Exception(sprintf("No user was found with name %s.", $groupMembershipHash['user']));
          }
        }
      } else {
        throw new Exception(sprintf("The group and user information is required."));
      }
    }
  }

  /**
   * @Given datasets:
   */
  public function addDatasets(TableNode $datasetsTable)
  {
    // Map readable field names to drupal field names.
    $field_map = array(
      'author' => 'author',
      'title' => 'title',
      'description' => 'body',
      'publisher' => 'og_group_ref',
      'date' => 'created',
      'published' => 'published',
      'resource format' => 'resource format',
      'tags' => 'field_tags',
    );

    foreach ($datasetsTable as $datasetHash) {
      $node = new stdClass();
      $node->type = 'group';
      foreach($datasetHash as $field => $value) {
        if(isset($field_map[$field])) {
          switch ($field) {

            case 'tags':
              $tags = taxonomy_vocabulary_machine_name_load('tags');
              $tag = $this->createTax($value, 'tags', $tags->vid);
              $value = array($value);

          }
          $drupal_field = $field_map[$field];
          $node->$drupal_field = $value;
        }
        else {
          throw new Exception(sprintf("Dataset's field %s doesn't exist, or hasn't been mapped. See FeatureContext::addDatasets for mappings.", $field));
        }
      }
      $created_node = $this->getDriver()->createNode($node);

      // Add the created node to the datasets array.
      $this->datasets[$created_node->nid] = $created_node;

      // Add the url to the page array for easy navigation.
      $this->addPage(array(
        'title' => $created_node->title,
        'url' => '/node/' . $created_node->nid
      ));
    }
  }

  public function validateJson() {
    $url = $this->getMinkParameter('base_url');

    // Get the schema and data as objects
    $retriever = new JsonSchema\Uri\UriRetriever;
    $schemaFile = __FILE__;
    $schemaFile = substr($schemaFile, 0, - strlen("features/bootstrap/FeatureContext.php"));
    $schemaFile = $schemaFile . 'schema/federal-v1.1/dataset.json';
    var_dump($schemaFile);
    $schema = $retriever->retrieve('file://' . $schemaFile);
    $data = json_decode(file_get_contents($url . '/data.json'));

    // If you use $ref or if you are unsure, resolve those references here
    // This modifies the $schema object
    //$refResolver = new JsonSchema\RefResolver($retriever);
    //$refResolver->resolve($schema, 'file://' . __DIR__);

    // Validate
    $validator = new JsonSchema\Validator();
    $validator->check($data, $schema);

    if ($validator->isValid()) {
        echo "The supplied JSON validates against the schema.\n";
    } else {
        echo "JSON does not validate. Violations:\n";
        foreach ($validator->getErrors() as $error) {
            echo sprintf("[%s] %s\n", $error['property'], $error['message']);
        }
    }
  }

  /**
   * @Then I should find a data.json file that passes POD :arg1 schema validator
   */
  public function iShouldFindADataJsonFileThatPassesPodSchemaValidator($arg1)
  {
      $this->validateJson();
      throw new PendingException();
  }

  /**
   * Explode a comma separated string in a standard way.
   *
   */
  function explode_list($string) {
    $array = explode(',', $string);
    $array = array_map('trim', $array);
    return is_array($array) ? $array : array();
  }

  /**
   * Looks up format if exists, if not creates it.
   *
   * @return object
   */
  public function createTax($name, $vocab_name, $vid) {
    if ($term = taxonomy_get_term_by_name($name, $vocab_name, $vid)) {
      $term = array_pop($term);
      return $term;
    }
    else {
      $this->termCreate($name);
    }
  }
}
