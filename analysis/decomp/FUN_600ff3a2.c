// 600ff3a2  FUN_600ff3a2  size=98 bytes
// --- callers ---
//   600959cc FUN_600959cc
// --- callees ---
//   600f3caa FUN_600f3caa
//   60095b2c FUN_60095b2c


void FUN_600ff3a2(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined1 local_d;
  int local_c;
  
  local_d = 0x85;
  local_c = FUN_60095b2c(*(undefined1 *)(param_2 + 0xe));
  if ((local_c != 0) &&
     (iVar1 = FUN_600f3caa(*(undefined1 *)(local_c + 0x1c),param_2 + 8,
                           *(undefined1 *)(param_2 + 0xf),*(undefined1 *)(param_2 + 0xf),param_2,
                           param_1), iVar1 != 0)) {
    local_d = 0;
  }
  if ((local_c != 0) && (*(int *)(local_c + 0x18) != 0)) {
    (**(code **)(local_c + 0x18))(0x11,&local_d);
  }
  return;
}


