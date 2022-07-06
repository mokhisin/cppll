#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>

#if __cplusplus < 201100
#error "C++11 or better is required"
#endif

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#define COMPILER_VALUE(value) (#value)

#ifdef __has_cpp_attribute
#define COMPILER_ATTRIBUTE_ENTRY(attr) \
    (#attr, COMPILER_VALUE(__has_cpp_attribute(attr)))
#else
#define __has_cpp_attribute(x) (0)
#define COMPILER_ATTRIBUTE_ENTRY(attr) (#attr, "_")
#endif

#ifdef _MSC_VER
#pragma warning(disable : 4127)
#endif

namespace _ {

    static struct PrintOptions {
        constexpr static bool TITLES = true;
        constexpr static bool ATTRIBUTES = true;
        constexpr static bool GENERAL_FEATURES = true;
        constexpr static bool CORE_FEATURES = true;
        constexpr static bool LIB_FEATURES = true;
        constexpr static bool SUPPORTED_FEATURES = true;
        constexpr static bool UNSUPPORTED_FEATURES = true;
        constexpr static bool SORTED_BY_VALUE = false;
        constexpr static bool CXX11 = true;
        constexpr static bool CXX14 = true;
        constexpr static bool CXX17 = true;
        constexpr static bool CXX20 = true;
        constexpr static bool CXX23 = true;
    } print;

    struct CompilerFeature {
        CompilerFeature(const char* name_, const char* value_) :
            name(name_), value(value_) {}
        const char* name;
        const char* value;
    };

    constexpr bool is_feature_supported(const CompilerFeature& x) {
        return x.value[0] != '_' && x.value[0] != '0';
    }

    static void show(const char* title, std::vector<CompilerFeature>& features) {
        if (print.TITLES) {
            std::cout << '\n' << std::left << title << '\n';
        }
        if (print.SORTED_BY_VALUE) {
            std::sort(
                std::begin(features), std::end(features),
                [](const CompilerFeature& lhs, const CompilerFeature& rhs) {
                    return std::strcmp(lhs.value, rhs.value) < 0;
                });
        }
        constexpr static int MAX_NAME_LENGTH = 44;
        for (const CompilerFeature& x : features) {
            std::string value = is_feature_supported(x) ? x.value : "------";
            if (value.back() == 'L') {
                value.pop_back();
            }
            if ((print.SUPPORTED_FEATURES && is_feature_supported(x))
                || (print.UNSUPPORTED_FEATURES && !is_feature_supported(x))) {
                std::cout << std::left << std::setw(MAX_NAME_LENGTH) << x.name
                    << " " << value << '\n';
            }
        }
    }

} // namespace _

#define COMPILER_FEATURE(name) (_::CompilerFeature{#name, COMPILER_VALUE(name)})
#define COMPILER_ATTRIBUTE(name) \
    (_::CompilerFeature COMPILER_ATTRIBUTE_ENTRY(name))

int main() {
    std::vector<_::CompilerFeature> cxx{
        COMPILER_FEATURE(__cplusplus),
        COMPILER_FEATURE(__cpp_exceptions),
        COMPILER_FEATURE(__cpp_rtti),
        COMPILER_FEATURE(__GNUC__),
        COMPILER_FEATURE(__GNUC_MINOR__),
        COMPILER_FEATURE(__GNUC_PATCHLEVEL__),
        COMPILER_FEATURE(__GNUG__),
        COMPILER_FEATURE(__clang__),
        COMPILER_FEATURE(__clang_major__),
        COMPILER_FEATURE(__clang_minor__),
        COMPILER_FEATURE(__clang_patchlevel__) };
    std::vector<_::CompilerFeature> cxx11{
        COMPILER_FEATURE(__cpp_alias_templates),
        COMPILER_FEATURE(__cpp_attributes),
        COMPILER_FEATURE(__cpp_constexpr),
        COMPILER_FEATURE(__cpp_decltype),
        COMPILER_FEATURE(__cpp_delegating_constructors),
        COMPILER_FEATURE(__cpp_inheriting_constructors),
        COMPILER_FEATURE(__cpp_initializer_lists),
        COMPILER_FEATURE(__cpp_lambdas),
        COMPILER_FEATURE(__cpp_nsdmi),
        COMPILER_FEATURE(__cpp_range_based_for),
        COMPILER_FEATURE(__cpp_raw_strings),
        COMPILER_FEATURE(__cpp_ref_qualifiers),
        COMPILER_FEATURE(__cpp_rvalue_references),
        COMPILER_FEATURE(__cpp_static_assert),
        COMPILER_FEATURE(__cpp_threadsafe_static_init),
        COMPILER_FEATURE(__cpp_unicode_characters),
        COMPILER_FEATURE(__cpp_unicode_literals),
        COMPILER_FEATURE(__cpp_user_defined_literals),
        COMPILER_FEATURE(__cpp_variadic_templates) };
    std::vector<_::CompilerFeature> cxx14{
        COMPILER_FEATURE(__cpp_aggregate_nsdmi),
        COMPILER_FEATURE(__cpp_binary_literals),
        COMPILER_FEATURE(__cpp_constexpr),
        COMPILER_FEATURE(__cpp_decltype_auto),
        COMPILER_FEATURE(__cpp_generic_lambdas),
        COMPILER_FEATURE(__cpp_init_captures),
        COMPILER_FEATURE(__cpp_return_type_deduction),
        COMPILER_FEATURE(__cpp_sized_deallocation),
        COMPILER_FEATURE(__cpp_variable_templates) };
    std::vector<_::CompilerFeature> cxx14lib{
        COMPILER_FEATURE(__cpp_lib_chrono_udls),
        COMPILER_FEATURE(__cpp_lib_complex_udls),
        COMPILER_FEATURE(__cpp_lib_exchange_function),
        COMPILER_FEATURE(__cpp_lib_generic_associative_lookup),
        COMPILER_FEATURE(__cpp_lib_integer_sequence),
        COMPILER_FEATURE(__cpp_lib_integral_constant_callable),
        COMPILER_FEATURE(__cpp_lib_is_final),
        COMPILER_FEATURE(__cpp_lib_is_null_pointer),
        COMPILER_FEATURE(__cpp_lib_make_reverse_iterator),
        COMPILER_FEATURE(__cpp_lib_make_unique),
        COMPILER_FEATURE(__cpp_lib_null_iterators),
        COMPILER_FEATURE(__cpp_lib_quoted_string_io),
        COMPILER_FEATURE(__cpp_lib_result_of_sfinae),
        COMPILER_FEATURE(__cpp_lib_robust_nonmodifying_seq_ops),
        COMPILER_FEATURE(__cpp_lib_shared_timed_mutex),
        COMPILER_FEATURE(__cpp_lib_string_udls),
        COMPILER_FEATURE(__cpp_lib_transformation_trait_aliases),
        COMPILER_FEATURE(__cpp_lib_transparent_operators),
        COMPILER_FEATURE(__cpp_lib_tuple_element_t),
        COMPILER_FEATURE(__cpp_lib_tuples_by_type) };
    std::vector<_::CompilerFeature> cxx17{
        COMPILER_FEATURE(__cpp_aggregate_bases),
        COMPILER_FEATURE(__cpp_aligned_new),
        COMPILER_FEATURE(__cpp_capture_star_this),
        COMPILER_FEATURE(__cpp_constexpr),
        COMPILER_FEATURE(__cpp_deduction_guides),
        COMPILER_FEATURE(__cpp_enumerator_attributes),
        COMPILER_FEATURE(__cpp_fold_expressions),
        COMPILER_FEATURE(__cpp_guaranteed_copy_elision),
        COMPILER_FEATURE(__cpp_hex_float),
        COMPILER_FEATURE(__cpp_if_constexpr),
        COMPILER_FEATURE(__cpp_inheriting_constructors),
        COMPILER_FEATURE(__cpp_inline_variables),
        COMPILER_FEATURE(__cpp_namespace_attributes),
        COMPILER_FEATURE(__cpp_noexcept_function_type),
        COMPILER_FEATURE(__cpp_nontype_template_args),
        COMPILER_FEATURE(__cpp_nontype_template_parameter_auto),
        COMPILER_FEATURE(__cpp_range_based_for),
        COMPILER_FEATURE(__cpp_static_assert),
        COMPILER_FEATURE(__cpp_structured_bindings),
        COMPILER_FEATURE(__cpp_template_template_args),
        COMPILER_FEATURE(__cpp_variadic_using) };
    std::vector<_::CompilerFeature> cxx17lib{
        COMPILER_FEATURE(__cpp_lib_addressof_constexpr),
        COMPILER_FEATURE(__cpp_lib_allocator_traits_is_always_equal),
        COMPILER_FEATURE(__cpp_lib_any),
        COMPILER_FEATURE(__cpp_lib_apply),
        COMPILER_FEATURE(__cpp_lib_array_constexpr),
        COMPILER_FEATURE(__cpp_lib_as_const),
        COMPILER_FEATURE(__cpp_lib_atomic_is_always_lock_free),
        COMPILER_FEATURE(__cpp_lib_bool_constant),
        COMPILER_FEATURE(__cpp_lib_boyer_moore_searcher),
        COMPILER_FEATURE(__cpp_lib_byte),
        COMPILER_FEATURE(__cpp_lib_chrono),
        COMPILER_FEATURE(__cpp_lib_clamp),
        COMPILER_FEATURE(__cpp_lib_enable_shared_from_this),
        COMPILER_FEATURE(__cpp_lib_execution),
        COMPILER_FEATURE(__cpp_lib_filesystem),
        COMPILER_FEATURE(__cpp_lib_gcd_lcm),
        COMPILER_FEATURE(__cpp_lib_hardware_interference_size),
        COMPILER_FEATURE(__cpp_lib_has_unique_object_representations),
        COMPILER_FEATURE(__cpp_lib_hypot),
        COMPILER_FEATURE(__cpp_lib_incomplete_container_elements),
        COMPILER_FEATURE(__cpp_lib_invoke),
        COMPILER_FEATURE(__cpp_lib_is_aggregate),
        COMPILER_FEATURE(__cpp_lib_is_invocable),
        COMPILER_FEATURE(__cpp_lib_is_swappable),
        COMPILER_FEATURE(__cpp_lib_launder),
        COMPILER_FEATURE(__cpp_lib_logical_traits),
        COMPILER_FEATURE(__cpp_lib_make_from_tuple),
        COMPILER_FEATURE(__cpp_lib_map_try_emplace),
        COMPILER_FEATURE(__cpp_lib_math_special_functions),
        COMPILER_FEATURE(__cpp_lib_memory_resource),
        COMPILER_FEATURE(__cpp_lib_node_extract),
        COMPILER_FEATURE(__cpp_lib_nonmember_container_access),
        COMPILER_FEATURE(__cpp_lib_not_fn),
        COMPILER_FEATURE(__cpp_lib_optional),
        COMPILER_FEATURE(__cpp_lib_parallel_algorithm),
        COMPILER_FEATURE(__cpp_lib_raw_memory_algorithms),
        COMPILER_FEATURE(__cpp_lib_sample),
        COMPILER_FEATURE(__cpp_lib_scoped_lock),
        COMPILER_FEATURE(__cpp_lib_shared_mutex),
        COMPILER_FEATURE(__cpp_lib_shared_ptr_arrays),
        COMPILER_FEATURE(__cpp_lib_shared_ptr_weak_type),
        COMPILER_FEATURE(__cpp_lib_string_view),
        COMPILER_FEATURE(__cpp_lib_to_chars),
        COMPILER_FEATURE(__cpp_lib_transparent_operators),
        COMPILER_FEATURE(__cpp_lib_type_trait_variable_templates),
        COMPILER_FEATURE(__cpp_lib_uncaught_exceptions),
        COMPILER_FEATURE(__cpp_lib_unordered_map_try_emplace),
        COMPILER_FEATURE(__cpp_lib_variant),
        COMPILER_FEATURE(__cpp_lib_void_t) };
    std::vector<_::CompilerFeature> cxx20{
        COMPILER_FEATURE(__cpp_aggregate_paren_init),
        COMPILER_FEATURE(__cpp_char8_t),
        COMPILER_FEATURE(__cpp_concepts),
        COMPILER_FEATURE(__cpp_conditional_explicit),
        COMPILER_FEATURE(__cpp_consteval),
        COMPILER_FEATURE(__cpp_constexpr),
        COMPILER_FEATURE(__cpp_constexpr_dynamic_alloc),
        COMPILER_FEATURE(__cpp_constexpr_in_decltype),
        COMPILER_FEATURE(__cpp_constinit),
        COMPILER_FEATURE(__cpp_deduction_guides),
        COMPILER_FEATURE(__cpp_designated_initializers),
        COMPILER_FEATURE(__cpp_generic_lambdas),
        COMPILER_FEATURE(__cpp_impl_coroutine),
        COMPILER_FEATURE(__cpp_impl_destroying_delete),
        COMPILER_FEATURE(__cpp_impl_three_way_comparison),
        COMPILER_FEATURE(__cpp_init_captures),
        COMPILER_FEATURE(__cpp_modules),
        COMPILER_FEATURE(__cpp_nontype_template_args),
        COMPILER_FEATURE(__cpp_using_enum) };
    std::vector<_::CompilerFeature> cxx20lib{
        COMPILER_FEATURE(__cpp_lib_array_constexpr),
        COMPILER_FEATURE(__cpp_lib_assume_aligned),
        COMPILER_FEATURE(__cpp_lib_atomic_flag_test),
        COMPILER_FEATURE(__cpp_lib_atomic_float),
        COMPILER_FEATURE(__cpp_lib_atomic_lock_free_type_aliases),
        COMPILER_FEATURE(__cpp_lib_atomic_ref),
        COMPILER_FEATURE(__cpp_lib_atomic_shared_ptr),
        COMPILER_FEATURE(__cpp_lib_atomic_value_initialization),
        COMPILER_FEATURE(__cpp_lib_atomic_wait),
        COMPILER_FEATURE(__cpp_lib_barrier),
        COMPILER_FEATURE(__cpp_lib_bind_front),
        COMPILER_FEATURE(__cpp_lib_bit_cast),
        COMPILER_FEATURE(__cpp_lib_bitops),
        COMPILER_FEATURE(__cpp_lib_bounded_array_traits),
        COMPILER_FEATURE(__cpp_lib_char8_t),
        COMPILER_FEATURE(__cpp_lib_chrono),
        COMPILER_FEATURE(__cpp_lib_concepts),
        COMPILER_FEATURE(__cpp_lib_constexpr_algorithms),
        COMPILER_FEATURE(__cpp_lib_constexpr_complex),
        COMPILER_FEATURE(__cpp_lib_constexpr_dynamic_alloc),
        COMPILER_FEATURE(__cpp_lib_constexpr_functional),
        COMPILER_FEATURE(__cpp_lib_constexpr_iterator),
        COMPILER_FEATURE(__cpp_lib_constexpr_memory),
        COMPILER_FEATURE(__cpp_lib_constexpr_numeric),
        COMPILER_FEATURE(__cpp_lib_constexpr_string),
        COMPILER_FEATURE(__cpp_lib_constexpr_string_view),
        COMPILER_FEATURE(__cpp_lib_constexpr_tuple),
        COMPILER_FEATURE(__cpp_lib_constexpr_utility),
        COMPILER_FEATURE(__cpp_lib_constexpr_vector),
        COMPILER_FEATURE(__cpp_lib_coroutine),
        COMPILER_FEATURE(__cpp_lib_destroying_delete),
        COMPILER_FEATURE(__cpp_lib_endian),
        COMPILER_FEATURE(__cpp_lib_erase_if),
        COMPILER_FEATURE(__cpp_lib_execution),
        COMPILER_FEATURE(__cpp_lib_format),
        COMPILER_FEATURE(__cpp_lib_generic_unordered_lookup),
        COMPILER_FEATURE(__cpp_lib_int_pow2),
        COMPILER_FEATURE(__cpp_lib_integer_comparison_functions),
        COMPILER_FEATURE(__cpp_lib_interpolate),
        COMPILER_FEATURE(__cpp_lib_is_constant_evaluated),
        COMPILER_FEATURE(__cpp_lib_is_layout_compatible),
        COMPILER_FEATURE(__cpp_lib_is_nothrow_convertible),
        COMPILER_FEATURE(__cpp_lib_is_pointer_interconvertible),
        COMPILER_FEATURE(__cpp_lib_jthread),
        COMPILER_FEATURE(__cpp_lib_latch),
        COMPILER_FEATURE(__cpp_lib_list_remove_return_type),
        COMPILER_FEATURE(__cpp_lib_math_constants),
        COMPILER_FEATURE(__cpp_lib_polymorphic_allocator),
        COMPILER_FEATURE(__cpp_lib_ranges),
        COMPILER_FEATURE(__cpp_lib_remove_cvref),
        COMPILER_FEATURE(__cpp_lib_semaphore),
        COMPILER_FEATURE(__cpp_lib_shared_ptr_arrays),
        COMPILER_FEATURE(__cpp_lib_shift),
        COMPILER_FEATURE(__cpp_lib_smart_ptr_for_overwrite),
        COMPILER_FEATURE(__cpp_lib_source_location),
        COMPILER_FEATURE(__cpp_lib_span),
        COMPILER_FEATURE(__cpp_lib_ssize),
        COMPILER_FEATURE(__cpp_lib_starts_ends_with),
        COMPILER_FEATURE(__cpp_lib_string_view),
        COMPILER_FEATURE(__cpp_lib_syncbuf),
        COMPILER_FEATURE(__cpp_lib_three_way_comparison),
        COMPILER_FEATURE(__cpp_lib_to_address),
        COMPILER_FEATURE(__cpp_lib_to_array),
        COMPILER_FEATURE(__cpp_lib_type_identity),
        COMPILER_FEATURE(__cpp_lib_unwrap_ref) };
    std::vector<_::CompilerFeature> cxx23{
        COMPILER_FEATURE(__cpp_if_consteval),
        COMPILER_FEATURE(__cpp_size_t_suffix) };
    std::vector<_::CompilerFeature> cxx23lib{
        COMPILER_FEATURE(__cpp_lib_constexpr_typeinfo),
        COMPILER_FEATURE(__cpp_lib_invoke_r),
        COMPILER_FEATURE(__cpp_lib_is_scoped_enum),
        COMPILER_FEATURE(__cpp_lib_stacktrace),
        COMPILER_FEATURE(__cpp_lib_stdatomic_h),
        COMPILER_FEATURE(__cpp_lib_string_contains),
        COMPILER_FEATURE(__cpp_lib_to_underlying),
        COMPILER_FEATURE(__cpp_lib_variant) };
    std::vector<_::CompilerFeature> attributes{
        COMPILER_ATTRIBUTE(carries_dependency),
        COMPILER_ATTRIBUTE(deprecated),
        COMPILER_ATTRIBUTE(fallthrough),
        COMPILER_ATTRIBUTE(likely),
        COMPILER_ATTRIBUTE(maybe_unused),
        COMPILER_ATTRIBUTE(nodiscard),
        COMPILER_ATTRIBUTE(noreturn),
        COMPILER_ATTRIBUTE(no_unique_address),
        COMPILER_ATTRIBUTE(unlikely) };

    if (_::print.GENERAL_FEATURES) {
        _::show("C++ GENERAL", cxx);
    }
    if (_::print.CXX11 && _::print.CORE_FEATURES) {
        _::show("C++11 CORE", cxx11);
    }
    if (_::print.CXX14 && _::print.CORE_FEATURES) {
        _::show("C++14 CORE", cxx14);
    }
    if (_::print.CXX14 && _::print.LIB_FEATURES) {
        _::show("C++14 LIB", cxx14lib);
    }
    if (_::print.CXX17 && _::print.CORE_FEATURES) {
        _::show("C++17 CORE", cxx17);
    }
    if (_::print.CXX17 && _::print.LIB_FEATURES) {
        _::show("C++17 LIB", cxx17lib);
    }
    if (_::print.CXX20 && _::print.CORE_FEATURES) {
        _::show("C++20 CORE", cxx20);
    }
    if (_::print.CXX20 && _::print.LIB_FEATURES) {
        _::show("C++20 LIB", cxx20lib);
    }
    if (_::print.CXX23 && _::print.CORE_FEATURES) {
        _::show("C++23 CORE", cxx23);
    }
    if (_::print.CXX23 && _::print.LIB_FEATURES) {
        _::show("C++23 LIB", cxx23lib);
    }
    if (_::print.ATTRIBUTES) {
        _::show("ATTRIBUTES", attributes);
    }
    return 0;
}
