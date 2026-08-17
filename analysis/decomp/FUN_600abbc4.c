// 600abbc4  FUN_600abbc4  size=42 bytes
// --- callers ---
//   600adad8 FUN_600adad8
// --- callees ---
//   600f3e6a FUN_600f3e6a


undefined2 FUN_600abbc4(undefined4 param_1)

{
  undefined2 local_a;
  
  local_a = 0xffff;
  FUN_600f3e6a(*(undefined1 *)(DAT_600abbf0 + 0xc20),param_1,&local_a,2);
  return local_a;
}


