//------------------------------------------------------------------------------
// GB_jit_kernel_subassign_22.c: C += y where C is dense, y is a scalar
//------------------------------------------------------------------------------

// SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2023, All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

//------------------------------------------------------------------------------

// Method 22: C += scalar, where C is dense

// M:           not present
// Mask_comp:   false
// Mask_struct: ignored
// C_replace:   false
// accum:       present
// A:           scalar, already cast to accum->ytype
// S:           none
// I:           NULL
// J:           NULL

GB_JIT_GLOBAL GB_JIT_KERNEL_SUBASSIGN_PROTO (GB_jit_kernel) ;
GB_JIT_GLOBAL GB_JIT_KERNEL_SUBASSIGN_PROTO (GB_jit_kernel)
{
    #ifdef GB_JIT_RUNTIME
    // get callback functions
    GB_free_memory_f GB_free_memory = my_callback->GB_free_memory_func ;
    GB_malloc_memory_f GB_malloc_memory = my_callback->GB_malloc_memory_func ;
    GB_ek_slice_f GB_ek_slice = my_callback->GB_ek_slice_func ;
    GB_werk_pop_f GB_werk_pop = my_callback->GB_werk_pop_func ;
    GB_werk_push_f GB_werk_push = my_callback->GB_werk_push_func ;
    #endif

    GB_Y_TYPE ywork = (*((GB_Y_TYPE *) scalar)) ;
    #include "GB_subassign_22_template.c"
    return (GrB_SUCCESS) ;
}

