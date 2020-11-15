#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "py/obj.h"
#include "shared-bindings/util.h"


void common_hal_testaddition_construct(abstract_module_t *self);
void common_hal_testaddion_deinit(abstract_module_t *self);
int common_hal_testaddion_sum(abstract_module_t *self, int a , int b);
int common_hal_testaddition_ten(abstract_module_t *self);
int common_hal_testaddition_past(abstract_module_t *self, int a);



m_generic_make(testaddition) {
    abstract_module_t * self = new_abstruct_module(type);
    mp_arg_check_num(n_args, n_kw, 0, 0, false);
    common_hal_testaddition_construct(self);
    return self;
}



mp_obj_t testaddition_sum(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args){
    abstract_module_t * self = (abstract_module_t *)(pos_args[0]);
    int a = mp_obj_get_int(pos_args[1]);
    int b = mp_obj_get_int(pos_args[2]);
    int r = common_hal_testaddition_sum(self, a, b); 

    return mp_obj_new_int(r);
}
 
MP_DEFINE_CONST_FUN_OBJ_KW(testaddition_sum_obj, 2, testaddition_sum);


mp_obj_t testaddition_ten(mp_obj_t self_in){
    int r = common_hal_testaddition_ten(self_in);  
    return mp_obj_new_int(r);
}

MP_DEFINE_CONST_FUN_OBJ_KW(testaddition_ten_obj, 0, testaddition_ten);

mp_obj_t testaddition_past(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args){
    abstract_module_t * self = (abstract_module_t *)(pos_args[0]);
    int a = mp_obj_get_int(pos_args[1]);
    int r = common_hal_testaddition_past(self, a); 

    return mp_obj_new_int(r);
}

MP_DEFINE_CONST_FUN_OBJ_KW(testaddition_past_obj, 1, testaddition_past);

const mp_rom_map_elem_t testaddition_locals_dict_table[] = {
    // instance methods
    { MP_ROM_QSTR(MP_QSTR_deinit),    MP_ROM_PTR(&testaddition_deinit_obj) },
    { MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&default___enter___obj) },
    { MP_ROM_QSTR(MP_QSTR___exit__),  MP_ROM_PTR(&testaddition_obj___exit___obj) },
    { MP_ROM_QSTR(MP_QSTR_sum),  MP_ROM_PTR(&testaddition_sum_obj)},
    { MP_ROM_QSTR(MP_QSTR_ten),  MP_ROM_PTR(&testaddition_ten_obj)},
    { MP_ROM_QSTR(MP_QSTR_past), MP_ROM_PTR(&testaddition_past_obj)}
};
 
MP_DEFINE_CONST_DICT(testaddition_locals_dict, testaddition_locals_dict_table);

const mp_obj_type_t testaddition_type = {
    {&mp_type_type},
    .name = MP_QSTR__testaddition,
    .make_new = testaddition_make_new,
    .locals_dict = (mp_obj_t)&testaddition_locals_dict,
};



