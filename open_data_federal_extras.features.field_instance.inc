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
    'description' => 'Adds Bureau Code, "Required If-Applicable" field for <a href="http://project-open-data.github.io/schema/#common-core-required-if-applicable-fields">Project Open Data</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 20,
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds Bureau Code, "Required If-Applicable" field for <a href="http://project-open-data.github.io/schema/#common-core-required-if-applicable-fields">Project Open Data</a>.');
  t('Bureau Code');

  return $field_instances;
}
