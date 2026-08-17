// 6009eb9c  FUN_6009eb9c  size=54 bytes
// --- callers ---
//   6009c444 FUN_6009c444
//   600b59ec FUN_600b59ec
//   6009c59c FUN_6009c59c
// --- callees ---


undefined4 FUN_6009eb9c(undefined2 param_1)

{
  undefined4 uVar1;
  undefined2 local_c [2];
  
  if (*(int *)(DAT_6009ebd4 + 0xd4) == 0) {
    uVar1 = 1;
  }
  else {
    local_c[0] = param_1;
    uVar1 = (**(code **)(DAT_6009ebd4 + 0xd4))(0x11,local_c);
  }
  return uVar1;
}


