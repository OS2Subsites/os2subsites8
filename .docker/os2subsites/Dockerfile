FROM drupal:8-apache-buster

# Installing additional dependencies.
RUN set -eux; \
	apt update; \
	apt install -qq -y \
		libxml2-dev \
		git \
		wget \
		mariadb-client-10.3 \
		pwgen \
		zip \
		cron \
		sudo; \
	docker-php-ext-install soap

# Removing standard Drupal core and loading OS2Web project.
WORKDIR /opt

ARG OS2SUBSITES8_TAG
RUN set -eux; \
	rm -rf drupal; \
#	PRODUCTION SETTINGS
#	Loading OS2Subsites via tags.	wget https://github.com/OS2Subsites/os2subsites8/archive/$OS2SUBSITES8_TAG.tar.gz; \
#	tar -xzvf $OS2SUBSITES8_TAG.tar.gz; \
#	rm $OS2SUBSITES8_TAG.tar.gz; \
#	mv os2subsites8-$OS2SUBSITES8_TAG drupal
#	DEVELOPMENT SETTINGS
#	Loading OS2Subsites from branch to avoid development releases.
	wget https://github.com/OS2Subsites/os2subsites8/archive/docker.zip; \
	unzip docker.zip; \
	rm docker.zip; \
	mv os2subsites8-docker drupal
WORKDIR /opt/drupal

# Loading composer dependencies and configuring project folders.
RUN set -eux; \
	export COMPOSER_HOME="$(mktemp -d)"; \
	composer global require hirak/prestissimo;\
	COMPOSER_MEMORY_LIMIT=-1 composer install; \
	chown -R www-data:www-data web/sites web/modules web/themes; \
	chmod +x scripts/os2subsites_provision/*.sh; \
	# delete composer cache.
	rm -rf "$COMPOSER_HOME"

# Adding further site specific data to image.
# Adding syn directory.
RUN mkdir -p config/default; \
	# Adjusting ownership
	chown -R www-data:www-data /opt/drupal/config/default /opt/drupal/tmp /opt/drupal/logs; \
	chmod g+s -R /opt/drupal/config/default /opt/drupal/logs

# Adding custom apache configuration with PHP value and log settings.
COPY apache/000-default.conf /etc/apache2/sites-enabled/000-default.conf

# Additional PHP configuration for both CLI and Apache
COPY php/os2subsites-php.ini /usr/local/etc/php/conf.d/os2subsites-php.ini

# Adding provisioning data to scripts.
COPY os2subsites_provision_config /opt/drupal/scripts/os2subsites_provision_config

# Adding provisioning data to scripts.
COPY --chown=www-data:www-data drupal/settings.php /opt/drupal/web/sites/default/settings.php

# Allow www-data call scripts.
COPY os2subsite /etc/sudoers.d/os2subsite

# Adding entry point where required services could be started.
COPY entrypoint.sh /usr/bin/

# Settings correct permissions.
RUN chmod +x /usr/bin/entrypoint.sh && chmod 0440 /etc/sudoers.d/os2subsite

# Adding missing HOME env variable.
# By some circumstances this variable is not availabe on subsite create process.
RUN echo "HOME=/opt/drupal" >> /opt/drupal/.env

# Addjusting output channels for access and error log.
RUN ln -sf /dev/stderr /var/log/apache2/error.log; \
	ln -sf /dev/stdout /var/log/apache2/access.log; \
	ln -sf /dev/stdout /var/log/apache2/other_vhosts_access.log

# Addjusting php runtime.
RUN ln -s /usr/local/bin/php /usr/bin/php;

ENTRYPOINT ["entrypoint.sh"]

CMD ["apache2-foreground"]
