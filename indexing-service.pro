TEMPLATE = subdirs

SUBDIRS += \
  actors \
  httpschemaplugin \
  indexing-client \
  indexing-service \
  test \
  libs/QGumboParser

test.depends = actors
