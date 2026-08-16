// 600a85b8  FUN_600a85b8  size=270 bytes
// --- callers ---
//   600a9234 FUN_600a9234
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006dbac FUN_6006dbac
//   6006dfa4 FUN_6006dfa4
//   600aa340 FUN_600aa340


void FUN_600a85b8(char param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  
  iVar2 = DAT_600a86c8;
  if ((((param_1 == '\0') &&
       (pbVar4 = (byte *)(param_2 + 8 + (uint)*(ushort *)(param_2 + 4)),
       uVar1 = (ushort)pbVar4[1] * 0x100 + (ushort)*pbVar4, uVar1 != 0xc03)) && (uVar1 != 0xc35)) &&
     (iVar3 = FUN_6006dbac(*(short *)(param_2 + 4) + *(short *)(param_2 + 2) + 8,DAT_600a86cc,0xd9),
     iVar3 != 0)) {
    thunk_EXT_FUN_0000b572(iVar3,param_2,8);
    if ((((uVar1 & 0xfc00) == 0xfc00) || (uVar1 == 0x2018)) || (uVar1 == 0x2017)) {
      thunk_EXT_FUN_0000b572(iVar3 + 8,param_2 + 8,4);
    }
    thunk_EXT_FUN_0000b572
              (iVar3 + 8 + (uint)*(ushort *)(iVar3 + 4),param_2 + 8 + (uint)*(ushort *)(param_2 + 4)
               ,*(undefined2 *)(param_2 + 2));
    FUN_6006dfa4(iVar2 + 0xac,iVar3);
    FUN_600aa340(iVar2 + 0xbc,0x2c,8);
  }
  return;
}


