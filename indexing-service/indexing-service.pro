TEMPLATE = subdirs

SUBDIRS += \
  actors \
  indexing-service

indexing-service.depends = actors
