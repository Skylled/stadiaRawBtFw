// 600a830c  FUN_600a830c  size=184 bytes
// --- callers ---
//   600a6b20 FUN_600a6b20
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600d92fc FUN_600d92fc
//   600d92f8 FUN_600d92f8
//   600d9290 FUN_600d9290


void FUN_600a830c(int param_1,char param_2,char param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uVar4;
  undefined4 local_14;
  
  uVar2 = DAT_600a83c4;
  if (param_3 == '\0') {
    uVar4 = 10;
  }
  else {
    uVar4 = 0;
  }
  for (local_14 = FUN_600d92f8(DAT_600a83c4); local_14 != 0; local_14 = FUN_600d92fc(local_14)) {
    iVar3 = thunk_EXT_FUN_0000b554(local_14 + 1,param_1 + 0x10,6);
    if ((((iVar3 == 0) && (*(short *)(local_14 + 8) == 0)) &&
        (param_2 == *(char *)(local_14 + 0x1c))) &&
       ((((cVar1 = **(char **)(local_14 + 0x10), param_3 == '\0' || (param_2 == '\x01')) ||
         ((cVar1 == '\x01' || (cVar1 == '\x02')))) ||
        ((cVar1 == '\x03' && ((*(ushort *)(param_1 + 0x2a) & 0x200) != 0)))))) {
      (**(code **)(local_14 + 0xc))(param_1 + 0x10,param_2,*(undefined4 *)(local_14 + 0x10),uVar4);
      FUN_600d9290(uVar2,local_14);
    }
  }
  return;
}


