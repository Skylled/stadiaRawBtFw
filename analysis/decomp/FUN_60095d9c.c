// 60095d9c  FUN_60095d9c  size=50 bytes
// --- callers ---
//   600fd520 FUN_600fd520
//   600fd464 FUN_600fd464
//   600fd5b2 FUN_600fd5b2
//   600fd60e FUN_600fd60e
//   600fd4e0 FUN_600fd4e0
//   600fd54e FUN_600fd54e
//   60093d20 FUN_60093d20
//   60095cd4 FUN_60095cd4
//   600fd48e FUN_600fd48e
//   600fd584 FUN_600fd584
//   600fd5da FUN_600fd5da
// --- callees ---


undefined4 FUN_60095d9c(undefined2 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(DAT_60095dd0 + 0x16c) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(DAT_60095dd0 + 0x16c))(param_1,param_2);
  }
  return uVar1;
}


