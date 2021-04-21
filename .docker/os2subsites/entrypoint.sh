#!/bin/bash

# Starting cron service.
service cron start

if [[ ! -f /opt/drupal/web/sites/default/settings.php ]]; then
    echo "Adding sites/default/settings.php file"
    mkdir -p /opt/drupal/web/sites/default/
    mkdir -p /opt/drupal/web/sites/default/files
    cp /opt/drupal/.docker/os2subsites/drupal/settings.php /opt/drupal/web/sites/default/settings.php
    chown www-data:www-data -R /opt/drupal/web/sites
    chmod g+s -R www-data:www-data -R /opt/drupal/web/sites
    chmod 755 /opt/drupal/web/sites/default
    chmod 644 /opt/drupal/web/sites/default/settings.php
fi

exec "$@"
