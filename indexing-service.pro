TEMPLATE = subdirs

SUBDIRS += \
  actors \
  httpfetchplugin \
  indexing-service \
  test \
  libs/QGumboParser

test.depends = actors
