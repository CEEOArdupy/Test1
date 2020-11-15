#include "addition/testaddition.h"
extern "C"{
#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "shared-bindings/util.h"
}

#define testaddition (*(Add *)self->module)

void * operator new(size_t, void *);

extern "C"{
    void common_hal_testaddition_construct(abstract_module_t *self){
        self->module = new (m_new_obj(Add)) Add();

    }

   void common_hal_testaddition_deinit(abstract_module_t *self){
        testaddition.~Add();
    }

    int common_hal_testaddition_sum(abstract_module_t *self, int a , int b){
        return testaddition.sum(a,b);
   
    }
    
    int common_hal_testaddition_ten(abstract_module_t *self){
        return testaddition.ten();
   
    }

     int common_hal_testaddition_past(abstract_module_t *self ,  int a ){
        return testaddition.past(a);
    }
}
