// 600e9e02  FUN_600e9e02  size=34 bytes
// --- callers ---
//   6008c834 bcm__6008c834
//   60085f2c pem_lib__60085f2c
// --- callees ---
//   6013cee8 thunk_EXT_FUN_0000af90
//   6013d208 thunk_EXT_FUN_0000ac5e


undefined4 FUN_600e9e02(int *param_1)

{
  code *pcVar1;
  
  if ((*param_1 != 0) && (pcVar1 = *(code **)(*param_1 + 0x24), pcVar1 != (code *)0x0)) {
    (*pcVar1)();
  }
  thunk_EXT_FUN_0000ac5e(param_1[2]);
  thunk_EXT_FUN_0000af90(param_1,0,0x88);
  return 1;
}


