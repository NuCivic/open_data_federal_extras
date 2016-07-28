<?php
/**
 * @file
 * open_data_federal_extras.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function open_data_federal_extras_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-dataset-field_odfe_bureau_code'
  $field_instances['node-dataset-field_odfe_bureau_code'] = array(
    'bundle' => 'dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Adds Project Open Data\'s <a href="https://project-open-data.cio.gov/v1.1/schema/#bureauCode">Bureau Code</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_odfe_bureau_code',
    'label' => 'Bureau Code',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'node-dataset-field_odfe_category'
  $field_instances['node-dataset-field_odfe_category'] = array(
    'bundle' => 'dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_odfe_category',
    'label' => 'Category',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'autocomplete_deluxe',
      'settings' => array(
        'autocomplete_deluxe_path' => 'autocomplete_deluxe/taxonomy',
        'delimiter' => ',',
        'limit' => 10,
        'min_length' => 0,
        'size' => 60,
      ),
      'type' => 'autocomplete_deluxe_taxonomy',
      'weight' => 35,
    ),
  );

  // Exported field_instance: 'node-dataset-field_odfe_conforms_to'
  $field_instances['node-dataset-field_odfe_conforms_to'] = array(
    'bundle' => 'dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is used to identify a standardized specification the dataset conforms to. If this is a technical specification associated with a particular serialization of a distribution, this should be specified with <a href="#distribution-conformsTo">conformsTo</a> at the distribution level. It’s recommended that this be a URI that serves as a unique identifier for the standard. The URI may or may not also be a URL that provides documentation of the specification. See <a href="https://project-open-data.cio.gov/v1.1/schema/#dataset-conformsTo">Data Standard at Project Open Data</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_odfe_conforms_to',
    'label' => 'Data Standard',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 0,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_maxlength' => 255,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 29,
    ),
  );

  // Exported field_instance: 'node-dataset-field_odfe_data_dictionary_type'
  $field_instances['node-dataset-field_odfe_data_dictionary_type'] = array(
    'bundle' => 'dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is used to identify the media type (IANA Media Type also known as MIME Type) of the URL used for the dataset’s describedBy field. This should be specified if describedBy is not an HTML webpage.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_odfe_data_dictionary_type',
    'label' => 'Data Dictionary Type',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-dataset-field_odfe_data_quality'
  $field_instances['node-dataset-field_odfe_data_quality'] = array(
    'bundle' => 'dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Indicates whether a dataset conforms to the agency’s information quality guidelines.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_odfe_data_quality',
    'label' => 'Data Quality',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 30,
    ),
  );

  // Exported field_instance: 'node-dataset-field_odfe_investment_uii'
  $field_instances['node-dataset-field_odfe_investment_uii'] = array(
    'bundle' => 'dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use to link a given dataset with its related IT Unique Investment Identifier, which can often be found in Exhibit 53 documents.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_odfe_investment_uii',
    'label' => 'primary IT Investment UII',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-dataset-field_odfe_is_part_of'
  $field_instances['node-dataset-field_odfe_is_part_of'] = array(
    'bundle' => 'dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This field allows the grouping of multiple datasets into a “collection”. This field should be employed by the individual datasets that together make up a collection. The value for this field should match the identifier of the parent dataset.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_odfe_is_part_of',
    'label' => 'Is Part Of',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-dataset-field_odfe_landing_page'
  $field_instances['node-dataset-field_odfe_landing_page'] = array(
    'bundle' => 'dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This field is not intended for an agency’s homepage (e.g. www.agency.gov), but rather if a dataset has a human-friendly hub or landing page that users can be directed to for all resources tied to the dataset.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_odfe_landing_page',
    'label' => 'Homepage URL',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 27,
    ),
  );

  // Exported field_instance: 'node-dataset-field_odfe_language'
  $field_instances['node-dataset-field_odfe_language'] = array(
    'bundle' => 'dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This should adhere to the RFC 5646 standard. This language subtag lookup provides a good tool for checking and verifying language codes. A language tag is comprised of either one or two parts, the language subtag (such as en for English, sp for Spanish, wo for Wolof) and the regional subtag (such as US for United States, GB for Great Britain, MX for Mexico), separated by a hyphen. Regional subtags should only be provided when needed to distinguish a language tag from another one (such as American vs. British English).',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_odfe_language',
    'label' => 'Language',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-dataset-field_odfe_program_code'
  $field_instances['node-dataset-field_odfe_program_code'] = array(
    'bundle' => 'dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Adds Project Open Data\'s <a href="https://project-open-data.cio.gov/v1.1/schema/#programCode">Program Code</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_odfe_program_code',
    'label' => 'Program Code',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 26,
    ),
  );

  // Exported field_instance: 'node-dataset-field_odfe_rights'
  $field_instances['node-dataset-field_odfe_rights'] = array(
    'bundle' => 'dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This may include information regarding access or restrictions based on privacy, security, or other policies. This should also serve as an explanation for the selected “accessLevel” including instructions for how to access a restricted file, if applicable, or explanation for why a “non-public” or “restricted public” data asset is not “public,” if applicable. If the dataset can be made available through a website indirectly, use accessURL for the URL that provides such access. See <a href="https://project-open-data.cio.gov/v1.1/schema/#rights">Rights on Project Open Data</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_odfe_rights',
    'label' => 'Rights',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 250,
      ),
      'type' => 'text_textfield',
      'weight' => 28,
    ),
  );

  // Exported field_instance: 'node-dataset-field_odfe_system_of_records'
  $field_instances['node-dataset-field_odfe_system_of_records'] = array(
    'bundle' => 'dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This field should a URL to the System of Records Notice (SORN) that relates to the dataset, specifically from FederalRegister.gov.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_odfe_system_of_records',
    'label' => 'System of Records',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 34,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds Project Open Data\'s <a href="https://project-open-data.cio.gov/v1.1/schema/#bureauCode">Bureau Code</a>.');
  t('Adds Project Open Data\'s <a href="https://project-open-data.cio.gov/v1.1/schema/#programCode">Program Code</a>.');
  t('Bureau Code');
  t('Category');
  t('Data Dictionary Type');
  t('Data Quality');
  t('Data Standard');
  t('Homepage URL');
  t('Indicates whether a dataset conforms to the agency’s information quality guidelines.');
  t('Is Part Of');
  t('Language');
  t('Program Code');
  t('Rights');
  t('System of Records');
  t('This field allows the grouping of multiple datasets into a “collection”. This field should be employed by the individual datasets that together make up a collection. The value for this field should match the identifier of the parent dataset.');
  t('This field is not intended for an agency’s homepage (e.g. www.agency.gov), but rather if a dataset has a human-friendly hub or landing page that users can be directed to for all resources tied to the dataset.');
  t('This field should a URL to the System of Records Notice (SORN) that relates to the dataset, specifically from FederalRegister.gov.');
  t('This is used to identify a standardized specification the dataset conforms to. If this is a technical specification associated with a particular serialization of a distribution, this should be specified with <a href="#distribution-conformsTo">conformsTo</a> at the distribution level. It’s recommended that this be a URI that serves as a unique identifier for the standard. The URI may or may not also be a URL that provides documentation of the specification. See <a href="https://project-open-data.cio.gov/v1.1/schema/#dataset-conformsTo">Data Standard at Project Open Data</a>.');
  t('This is used to identify the media type (IANA Media Type also known as MIME Type) of the URL used for the dataset’s describedBy field. This should be specified if describedBy is not an HTML webpage.');
  t('This may include information regarding access or restrictions based on privacy, security, or other policies. This should also serve as an explanation for the selected “accessLevel” including instructions for how to access a restricted file, if applicable, or explanation for why a “non-public” or “restricted public” data asset is not “public,” if applicable. If the dataset can be made available through a website indirectly, use accessURL for the URL that provides such access. See <a href="https://project-open-data.cio.gov/v1.1/schema/#rights">Rights on Project Open Data</a>.');
  t('This should adhere to the RFC 5646 standard. This language subtag lookup provides a good tool for checking and verifying language codes. A language tag is comprised of either one or two parts, the language subtag (such as en for English, sp for Spanish, wo for Wolof) and the regional subtag (such as US for United States, GB for Great Britain, MX for Mexico), separated by a hyphen. Regional subtags should only be provided when needed to distinguish a language tag from another one (such as American vs. British English).');
  t('Use to link a given dataset with its related IT Unique Investment Identifier, which can often be found in Exhibit 53 documents.');
  t('primary IT Investment UII');

  return $field_instances;
}
