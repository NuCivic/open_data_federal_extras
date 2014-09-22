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
    'default_value' => array(
      0 => array(
        'value' => '184-015',
      ),
    ),
    'deleted' => 0,
    'description' => 'Adds Bureau Code, "Required If-Applicable" field for <a href="http://project-open-data.github.io/schema/#common-core-required-if-applicable-fields">Project Open Data</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 24,
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
      'weight' => 27,
    ),
  );

  // Exported field_instance: 'node-dataset-field_odfe_landing_page'
  $field_instances['node-dataset-field_odfe_landing_page'] = array(
    'bundle' => 'dataset',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 21,
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
    'label' => 'Landing Page',
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
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
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
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'node-dataset-field_odfe_program_code'
  $field_instances['node-dataset-field_odfe_program_code'] = array(
    'bundle' => 'dataset',
    'default_value' => array(
      0 => array(
        'value' => '005-003',
      ),
    ),
    'deleted' => 0,
    'description' => 'Adds Program Code, "Required If-Applicable" field for <a href="http://project-open-data.github.io/schema/#common-core-required-if-applicable-fields">Project Open Data</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 23,
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
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 26,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds Bureau Code, "Required If-Applicable" field for <a href="http://project-open-data.github.io/schema/#common-core-required-if-applicable-fields">Project Open Data</a>.');
  t('Adds Program Code, "Required If-Applicable" field for <a href="http://project-open-data.github.io/schema/#common-core-required-if-applicable-fields">Project Open Data</a>.');
  t('Bureau Code');
  t('Landing Page');
  t('Program Code');

  return $field_instances;
}
