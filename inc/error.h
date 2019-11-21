#ifndef _ERROR_H_
#define _ERROR_H_


typedef long                 STATUS;


#define MAKE_ERROR( \
  Facility, \
  Code) \
( \
  0xA0000000 | ((Facility) << 16) | (Code) \
)

#define MAKE_SUCCESS( \
  Facility, \
  Code) \
( \
  0x20000000 | ((Facility) << 16) | (Code) \
)

#define STATUS_ERROR( \
  Status) \
( \
  (Status) & 0x80000000 \
)

#define STATUS_GET_FACILITY( \
  Status) \
( \
  ((Status) >> 16) & 0x7FF \
)

#define STATUS_GET_CODE( \
  Status) \
( \
  (Status) & 0xFF \
)

#define NULL_STATUS_FACILITY  0x000

#define STATUS_CODE_SUCCESS        0x0000
#define STATUS_CODE_NULL_REFERENCE 0x0001
#define STATUS_CODE_BAD_ALLOC      0x0002

#define STATUS_SUCCESS MAKE_SUCCESS(NULL_STATUS_FACILITY, STATUS_CODE_SUCCESS)


#endif
