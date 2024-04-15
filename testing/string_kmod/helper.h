#ifdef __cplusplus
extern "C" {
#endif

void initialize_cpp_string(char* data);
const char* get_cpp_string(void);
size_t set_cpp_string(const char* new_data);
size_t get_cpp_string_size(void);
void deinitialize_cpp_string(void);

#ifdef __cplusplus
}
#endif