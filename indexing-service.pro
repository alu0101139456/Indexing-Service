TEMPLATE = subdirs

SUBDIRS += \
  actors \
  httpschemaplugin \
  indexing-service \
  test \
  libs/QGumboParser

test.depends = actors
