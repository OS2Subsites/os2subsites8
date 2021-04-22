# OS2Subsites Drupal 8 project

## Usage

* Clone the repository

```
git@github.com:OS2Subsites/os2subsites8.git
```
* Rename your installation if needed

* Go to the installation and start composer

```
composer install
```

* Follow the regular install process, select ```OS2Web``` as install profile.

* By default profile doesn't have installed theme. After installation is done,
 you need to:
    * enable Designsystem.dk - theme that recommended to use as project theme
    * enable [OS2Web Pagebuilder module](https://github.com/OS2web/os2web_pagebuilder),
     that brings you some default entities and settings.
        ```
        drush theme:enable fds_custom_theme
        drush config-set system.theme default fds_custom_theme -y
        drush en -y os2web_pagebuilder
        drush en -y os2web_spotbox os2web_contact os2web_banner_paragraph
        ```
* Enable other modules from OS2Web category and setup them on demand.

## Subsites provisioning setup

Read about how to setup subsites provisioning in [README file](https://github.com/bellcom/os2subsite_provision)

## Contribution

OS2Subsite projects is opened for new features and os course bugfixes.
If you have any suggestion or you found a bug in project, you are very welcome
to create an issue in github repository issue tracker.
For issue description there is expected that you will provide clear and
sufficient information about your feature request or bug report.

### Code review policy
See [OS2Web code review policy](https://github.com/OS2Web/docs#code-review)

### Git name convention
See [OS2Web git name convention](https://github.com/OS2Web/docs#git-guideline)

## Develompent

In case you had issues during subsites installation process, you can try to
reproduce in locally on your local machine via Drush.
Steps:
1. Update your local db with recent changes from project configuration fo which
you suppose to use.
2. Export configuration to sync folder. Usually it will be `config/sync`.
3. Run installation process from existing config:
```
drush si --existing-config
```

## Commands

* Setup cron command for subsites administration installation
Inside container run following command. Make sure that `/var/spool/cron/crontabs` folder is added as volume.
```
/usr/bin/crontab -l; echo "00 */2 * * * /opt/drupal/vendor/bin/drush cron --root=/opt/drupal") | /usr/bin/crontab -
```
