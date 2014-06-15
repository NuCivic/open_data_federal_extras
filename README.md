Open Data Federal Agency Extras module
========================

Open Data Federal Agency Extras module. Extends DKAN Dataset to include selected Project Open Data and other federal requirements

## Additional Fields

 * Bureau Code
 * Landing Page

### Requirements
Requires DKAN Dataset module.

### Update Fed list
1. Go to http://project-open-data.github.io/schema/#programCode
2. Download "Federal Program Inventory"
3. Export in csv to ``fed_bureau_code_list``
4. cd 'fed_bureau_code_list'
5. Run ``php -r " require 'list_to_array.php'; opfe_list_to_array_process();``
