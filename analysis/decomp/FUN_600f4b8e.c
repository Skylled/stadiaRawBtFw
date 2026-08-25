// 600f4b8e  FUN_600f4b8e  size=296 bytes
// --- callers ---
//   600acf50 FUN_600acf50
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f46ee FUN_600f46ee
//   600f47a0 FUN_600f47a0
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600b00b4 FUN_600b00b4


void FUN_600f4b8e(undefined4 param_1,int param_2,undefined4 param_3,short param_4,byte *param_5)

{
  int iVar1;
  undefined1 auStack_278 [2];
  short local_276;
  short local_274;
  short local_272;
  undefined1 auStack_26f [603];
  byte *local_14;
  
  local_14 = param_5;
  thunk_EXT_FUN_0000b5ba(auStack_278,0,0x262);
  local_276 = (ushort)local_14[1] * 0x100 + (ushort)*local_14;
  local_274 = (ushort)local_14[3] * 0x100 + (ushort)local_14[2];
  local_14 = local_14 + 4;
  local_272 = param_4 + -4;
  thunk_EXT_FUN_0000b572(auStack_26f,local_14,local_272);
  if (*(char *)(param_2 + 0x32) == '\x03') {
    *(undefined1 *)(param_2 + 0x33) = 0;
    FUN_600b00b4(param_2,*(undefined1 *)(param_2 + 0x33),auStack_278);
  }
  else if ((*(char *)(param_2 + 0x32) == '\x02') &&
          (iVar1 = FUN_600f46ee(param_1,param_2,auStack_278), iVar1 == 0)) {
    FUN_600f47a0(param_1,param_2);
  }
  return;
}


