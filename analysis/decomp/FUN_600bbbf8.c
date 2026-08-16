// 600bbbf8  FUN_600bbbf8  size=318 bytes
// --- callers ---
//   600ba1c4 FUN_600ba1c4
// --- callees ---
//   600b9408 FUN_600b9408
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600bb7e4 FUN_600bb7e4


void FUN_600bbbf8(undefined4 param_1,undefined1 param_2,short param_3)

{
  int iVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  undefined4 local_10;
  undefined2 local_a;
  
  local_a = 4;
  if (param_3 == 3) {
    local_a = 0xc;
  }
  else if (param_3 == 1) {
    local_a = 6;
  }
  iVar1 = FUN_600bb7e4(param_1,local_a,0xb,param_2);
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x14) = (char)param_3;
    puVar2 = (undefined1 *)(iVar1 + 0x16);
    *(char *)(iVar1 + 0x15) = (char)((ushort)param_3 >> 8);
    if (param_3 == 3) {
      *puVar2 = 0;
      pbVar3 = (byte *)(iVar1 + 0x18);
      *(undefined1 *)(iVar1 + 0x17) = 0;
      thunk_EXT_FUN_0000b5ba(pbVar3,0,8);
      *pbVar3 = 2;
      for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
        if (*(int *)(local_10 * 0x1c + DAT_600bbd38 + 0xed0) != 0) {
          *pbVar3 = (byte)(1 << (local_10 + 4U & 0xff)) | *pbVar3;
        }
      }
      *pbVar3 = *pbVar3 & 0xe;
    }
    else if (param_3 == 1) {
      *puVar2 = 0;
      *(undefined1 *)(iVar1 + 0x17) = 0;
      *(undefined1 *)(iVar1 + 0x18) = 0x48;
      *(undefined1 *)(iVar1 + 0x19) = 2;
    }
    else {
      *puVar2 = 1;
      *(undefined1 *)(iVar1 + 0x17) = 0;
    }
    FUN_600b9408(param_1,0,iVar1);
  }
  return;
}


