#include <papi.h>
#include <stdio.h>

#define TRUE 1

main()
{
int EventSet = PAPI_NULL;
unsigned int native = 0x0;
int retval, i;
PAPI_event_info_t info;
PAPI_event_info_t *infostructs;

/* Initialize the library */
retval = PAPI_library_init(PAPI_VER_CURRENT);

if (retval != PAPI_VER_CURRENT) {
        fprintf(stderr,"PAPI library init error!\n");
        exit(1);
}

/* Check to see if the preset, PAPI_TOT_INS, exists */
if (PAPI_query_event (PAPI_TOT_INS) != PAPI_OK) {
fprintf (stderr,"No PAPI_TOT_INS.\n");
exit(1);
}

/* Get details about the preset, PAPI_TOT_INS */
if (PAPI_get_event_info(PAPI_TOT_INS,&info) != PAPI_OK) {
fprintf (stderr,"No PAPI_TOT_INS.\n");
exit(1);
}

if (info.count>0)
  printf ("This event PAPI_TOT_INS is available on this hardware.\n");

/* Check to see if the preset, PAPI_TOT_INS, exists */
if (PAPI_query_event (PAPI_FP_OPS) != PAPI_OK) {
fprintf (stderr,"No PAPI_FP_OPS.\n");
exit(1);
}

/* Get details about the preset, PAPI_TOT_INS */
if (PAPI_get_event_info(PAPI_FP_OPS,&info) != PAPI_OK) {
fprintf (stderr,"No PAPI_FP_OPS.\n");
exit(1);
}

if (info.count>0)
  printf ("This event PAPI_FP_OPS is available on this hardware.\n");

return(1);
}
