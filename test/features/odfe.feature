Feature: Project Open Data Feature
  In order to meet POD requirements
  As a dataset creator
  I want to create datasets with POD fields and publish them with data.json

  @api
  Scenario: Know that data.json file is valid
    Given I visit "data.json"
    Then I should find a data.json file that passes POD 1.1 schema validator

  @api
  Scenario: See POD fields on the Dataset form
    Given I am logged in as a user with the "editor" role
    When I visit "node/add/dataset"
    Then I should see "Project Open Data Fields"
    And I should see "These are fields that are specific to Project Open Data."
    And I should see all of the POD fields

