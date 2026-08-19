// 600df878  FUN_600df878  size=40 bytes
// --- callers ---
//   6004cbf0 device_info__6004cbf0
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600df810 FUN_600df810


void FUN_600df878(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_24 [12];
  undefined4 local_18;
  
  thunk_EXT_FUN_0000b5ba(auStack_24,0,0x14);
  iVar1 = FUN_600df810(auStack_24,param_2,param_3);
  if (iVar1 != 0) {
    *param_1 = local_18;
  }
  return;
}


