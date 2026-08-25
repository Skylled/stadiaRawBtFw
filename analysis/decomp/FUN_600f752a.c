// 600f752a  FUN_600f752a  size=150 bytes
// --- callers ---
//   600a1394 FUN_600a1394
// --- callees ---
//   600a9234 FUN_600a9234


void FUN_600f752a(int param_1,undefined2 param_2,byte param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  undefined1 *local_14;
  
  *(ushort *)(param_1 + 2) = param_3 + 3;
  *(undefined2 *)(param_1 + 4) = 4;
  *(undefined4 *)(param_1 + 8) = param_5;
  *(char *)(param_1 + 0xc) = (char)param_2;
  *(byte *)(param_1 + 0xd) = (byte)((ushort)param_2 >> 8) | 0xfc;
  *(byte *)(param_1 + 0xe) = param_3;
  iVar1 = 0;
  local_14 = (undefined1 *)(param_1 + 0xf);
  while( true ) {
    if ((int)(uint)param_3 <= iVar1) break;
    *local_14 = *(undefined1 *)(iVar1 + param_4);
    iVar1 = iVar1 + 1;
    local_14 = local_14 + 1;
  }
  FUN_600a9234(0,param_1);
  return;
}


