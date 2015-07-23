<?php
/**
 * @file
 * open_data_federal_extras.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function open_data_federal_extras_taxonomy_default_vocabularies() {
  return array(
    'odfe_theme' => array(
      'name' => 'Category',
      'machine_name' => 'odfe_theme',
      'description' => 'Project Open Data Category',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
