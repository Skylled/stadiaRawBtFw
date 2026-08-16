// 60058510  FUN_60058510  size=58 bytes
// --- callers ---
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   601015e6 FUN_601015e6


void FUN_60058510(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = DAT_6005854c;
  if (*DAT_6005854c != '\0') {
    return;
  }
  thunk_EXT_FUN_0000b4c2(DAT_60058550);
  if (*(byte *)(param_1 + 10) < (byte)pcVar1[1]) {
    pcVar2 = DAT_60058554;
    if (*(byte *)(param_1 + 10) < (byte)pcVar1[2]) goto LAB_60058532;
  }
  else {
    pcVar2 = pcVar1 + 0x804;
  }
  FUN_601015e6(pcVar2,param_1);
LAB_60058532:
  thunk_EXT_FUN_00007d10(DAT_60058550);
  return;
}


