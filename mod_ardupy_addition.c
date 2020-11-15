#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "py/obj.h"
#include "shared-bindings/util.h"


void common_hal_add_construct(abstract_module_t *self, int count);
void common_hal_add_deinit(abstract_module_t *self);
float common_hal_add_sum(abstract_module_t *self, int a , int b);

m_generic_make(add) {
    abstract_module_t * self = new_abstruct_module(type);
    mp_arg_check_num(n_args, n_kw, 0, 0, false);
    common_hal_add_construct(self, count);
    return self;
}

void add_obj_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest){
    abstract_module_t *self = (abstract_module_t *)self_in;
    uint32_t value;
    float number;
    if (dest[0] == MP_OBJ_NULL) {
        if (attr == MP_QSTR_sum) {
            number = common_hal_add_sum(self, a,b); // Call previously defined unction
            dest[0] = mp_obj_new_float(number); // This the MicroPython float type, should match with the data type
            return;
        }
        
    }
    generic_method_lookup(self_in, attr, dest);
}

const mp_rom_map_elem_t add_locals_dict_table[] = {
    // instance methods
    { MP_ROM_QSTR(MP_QSTR_deinit),    MP_ROM_PTR(&add_deinit_obj) },
    { MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&default___enter___obj) },
    { MP_ROM_QSTR(MP_QSTR___exit__),  MP_ROM_PTR(&add_obj___exit___obj) },
};
 
MP_DEFINE_CONST_DICT(add_locals_dict, add_locals_dict_table);

const mp_obj_type_t add_type = {
    {&mp_type_type},
    .name = MP_QSTR_milan_add,
    .make_new = add_make_new,
    .locals_dict = (mp_obj_t)&add_locals_dict,
    .attr = add_obj_attr,
};



