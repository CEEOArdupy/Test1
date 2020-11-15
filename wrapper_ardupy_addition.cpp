#include "addition/testaddition.h"
extern "C"{
#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "shared-bindings/util.h"
}

#define add (*(add*)self->module) //class name is add
void * operator new(size_t, void *);

extern "C" {
    bool common_hal_add_construct(abstract_module_t *self){
        self->module = new (m_new_obj(add)) add();
        add.init();
    }
   void common_hal_add_deinit(abstract_module_t *self){
        add.~add();
    }
    float common_hal_add_sum(abstract_module_t *self, int a , int b){
        return add.sum(a,b);
   
    }
}