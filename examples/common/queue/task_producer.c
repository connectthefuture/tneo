/*******************************************************************************
 *    Description: TODO
 *
 ******************************************************************************/


/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

#include <xc.h>
#include <plib.h>
#include "task_producer.h"
#include "queue_example.h"
#include "tn.h"

/*******************************************************************************
 *    DEFINITIONS
 ******************************************************************************/

//-- task stack size
#define  TASK_PRODUCER_STACK_SIZE      (TN_MIN_STACK_SIZE + 96)

//-- highest priority
#define  TASK_PRODUCER_PRIORITY        0 



/*******************************************************************************
 *    PRIVATE FUNCTION PROTOTYPES
 ******************************************************************************/

/*******************************************************************************
 *    PRIVATE TYPES
 ******************************************************************************/

/*******************************************************************************
 *    PRIVATE DATA
 ******************************************************************************/

//-- define array for task stack
TN_STACK_ARR_DEF(task_producer_stack, TASK_PRODUCER_STACK_SIZE);

//-- task descriptor: it's better to explicitly zero it
static struct TN_Task task_producer = {};



/*******************************************************************************
 *    PUBLIC DATA
 ******************************************************************************/

/*******************************************************************************
 *    EXTERNAL DATA
 ******************************************************************************/

/*******************************************************************************
 *    EXTERNAL FUNCTION PROTOTYPES
 ******************************************************************************/

/*******************************************************************************
 *    PRIVATE FUNCTIONS
 ******************************************************************************/

static void task_producer_body(void *par)
{
   for (;;)
   {
      SYSRETVAL_CHECK_TO( tn_task_sleep(100) );
   }
}



/*******************************************************************************
 *    PUBLIC FUNCTIONS
 ******************************************************************************/

void task_producer_create(void)
{

   SYSRETVAL_CHECK(
         tn_task_create(
            &task_producer,
            task_producer_body,
            TASK_PRODUCER_PRIORITY,
            task_producer_stack,
            TASK_PRODUCER_STACK_SIZE,
            NULL,
            (TN_TASK_CREATE_OPT_START)
            )
         );

}





/*******************************************************************************
 *    end of file
 ******************************************************************************/


