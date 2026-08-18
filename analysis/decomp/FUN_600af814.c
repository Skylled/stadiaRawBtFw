// 600af814  FUN_600af814  size=66 bytes
// --- callers ---
//   600f3caa FUN_600f3caa
//   600f3e6a FUN_600f3e6a
//   600f5bfc FUN_600f5bfc
//   600f5ce2 FUN_600f5ce2
//   600ac22c FUN_600ac22c
//   600ad868 FUN_600ad868
//   600f3bde FUN_600f3bde
//   600abb14 FUN_600abb14
//   600f5b32 FUN_600f5b32
//   600f7278 FUN_600f7278
//   600f7052 FUN_600f7052
//   600f74a8 FUN_600f74a8
//   600ac128 FUN_600ac128
//   600b02e0 FUN_600b02e0
// --- callees ---
//   600af75c FUN_600af75c


int FUN_600af814(undefined4 param_1,undefined1 param_2)

{
  byte bVar1;
  undefined4 local_c;
  
  local_c = 0;
  bVar1 = FUN_600af75c(param_1,param_2);
  if (bVar1 != 0xff) {
    local_c = (uint)bVar1 * 0x10c + DAT_600af858;
  }
  return local_c;
}


