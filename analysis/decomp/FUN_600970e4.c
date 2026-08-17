// 600970e4  FUN_600970e4  size=104 bytes
// --- callers ---
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6006ecfc FUN_6006ecfc


undefined4 FUN_600970e4(undefined1 *param_1)

{
  undefined2 local_18;
  undefined1 local_16;
  byte local_15;
  undefined1 local_14;
  undefined1 *local_c;
  
  *(undefined1 *)(DAT_6009714c + 0xb) = *param_1;
  local_c = param_1;
  thunk_EXT_FUN_0000b5ba(&local_18,0,10);
  local_18 = *(undefined2 *)(local_c + 2);
  local_16 = local_c[1];
  local_15 = (byte)*(undefined4 *)(local_c + 4) & 1;
  local_14 = 0;
  *(undefined4 *)(DAT_6009714c + 0x10) = *(undefined4 *)(local_c + 4);
  *(undefined1 *)(DAT_6009714c + 0xc) = 2;
  FUN_6006ecfc(*local_c,&local_18,DAT_60097150);
  return 1;
}


