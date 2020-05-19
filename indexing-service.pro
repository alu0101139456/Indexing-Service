TEMPLATE = subdirs

SUBDIRS += \
  actors \
  indexing-service \
  test

test.depends = actors
