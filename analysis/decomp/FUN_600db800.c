// 600db800  FUN_600db800  size=30 bytes
// --- callers ---
//   60079778 http_flash_writer__60079778
//   6007991c http_flash_writer__6007991c
// --- callees ---
//   6005a9fc FUN_6005a9fc
//   6004cb28 FUN_6004cb28


void FUN_600db800(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = param_2;
  uVar1 = FUN_6004cb28(param_2);
  FUN_6005a9fc(param_1,0,*(undefined4 *)(param_1 + 4),param_2,uVar1,uVar2,param_3);
  return;
}


