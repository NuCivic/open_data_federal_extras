#!/bin/bash

mysql -e "create database dkan_odfe_test"
git clone https://github.com/NuCivic/dkan-drops-7.git dkan_test
cd dkan_test

drush si dkan --account-pass=admin --db-url="mysql://root:root@localhost/dkan_odfe_test"
