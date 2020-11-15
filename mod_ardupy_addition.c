#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "py/obj.h"
#include "shared-bindings/util.h"


void common_hal_add_construct(abstract_module_t *self);
void common_hal_add_deinit(abstract_module_t *self);
uint common_hal_add_sum(abstract_module_t *self, uint a , uint b);

m_generic_make(add) {
    abstract_module_t * self = new_abstruct_module(type);
    mp_arg_check_num(n_args, n_kw, 0, 0, false);
    common_hal_add_construct(self);
    return self;
}



uint add_sum(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args){
    abstract_module_t * self = (abstract_module_t *)(pos_args[0]);
    uint a = mp_obj_get_int(pos_args[1]);
    uint b = mp_obj_get_int(pos_args[2]);
    uint r = common_hal_add_sum(self, a, b);
    return r;
}
 
MP_DEFINE_CONST_FUN_OBJ_KW(add_sum_obj, 2, add_sum);

const mp_rom_map_elem_t add_locals_dict_table[] = {
    // instance methods
    { MP_ROM_QSTR(MP_QSTR_deinit),    MP_ROM_PTR(&add_deinit_obj) },
    { MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&default___enter___obj) },
    { MP_ROM_QSTR(MP_QSTR___exit__),  MP_ROM_PTR(&add_obj___exit___obj) },
     {MP_ROM_QSTR(MP_QSTR_sum), MP_ROM_PTR(&add_sum_obj)},
};
 
MP_DEFINE_CONST_DICT(add_locals_dict, add_locals_dict_table);

const mp_obj_type_t add_type = {
    {&mp_type_type},
    .name = MP_QSTR__add,
    .make_new = add_make_new,
    .locals_dict = (mp_obj_t)&add_locals_dict,
};



