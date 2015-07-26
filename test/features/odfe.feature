Feature: Project Open Data Feature
  In order to meet POD requirements
  As a dataset creator
  I want to create datasets with POD fields and publish them with data.json

 Background:
    Given users:
      | name    | mail             | roles         |
      | John    | john@test.com    | administrator |
      | Gabriel | gabriel@test.com | editor        |
      | Jaz     | jaz@test.com     | editor        |
    And datasets:
      | title      |  author  | published | date         | tags   |
      | Dataset 01 |  Gabriel | Yes       | Feb 01, 2015 | Health |
      | Dataset 02 |  Jaz     | Yes       | Mar 13, 2015 | Gov    |

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

