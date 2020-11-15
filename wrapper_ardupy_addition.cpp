#include "addition/testaddition.h"
extern "C"{
#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "shared-bindings/util.h"
}

#define adder (*(add *)self->module)

void * operator new(size_t, void *);

extern "C"{
    void common_hal_add_construct(abstract_module_t *self){
        self->module = new (m_new_obj(add)) add();

    }

   void common_hal_add_deinit(abstract_module_t *self){
        adder.~add();
    }

    int32_t common_hal_add_sum(abstract_module_t *self, int32_t a , int32_t b){
        return adder.sum(a,b);
   
    }
}
