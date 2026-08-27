// 6005f9a8  FUN_6005f9a8  size=86 bytes
// --- callers ---
//   600cbdc8 xbara__600cbdc8
// --- callees ---
//   600d48c4 FUN_600d48c4
//   601017e8 FUN_601017e8
//   6013d230 thunk_EXT_FUN_00000348


char FUN_6005f9a8(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar6 = DAT_6005fa00;
  if (*(char *)((int)param_1 + 0x19) == '\0') {
    FUN_601017e8(param_1 + 7);
    puVar2 = (undefined4 *)(**(code **)(*param_1 + 0x28))(param_1);
    puVar4 = puVar2;
    do {
      puVar5 = puVar4 + 2;
      uVar3 = puVar4[1];
      *puVar6 = *puVar4;
      puVar6[1] = uVar3;
      puVar6 = puVar6 + 2;
      puVar4 = puVar5;
    } while (puVar5 != puVar2 + 8);
    thunk_EXT_FUN_00000348(DAT_6005fa08,4,DAT_6005fa04,0x3c);
    cVar1 = FUN_600d48c4(param_1 + 0x1c);
    if (cVar1 == '\0') {
      *(undefined1 *)((int)param_1 + 0x19) = 1;
    }
  }
  else {
    cVar1 = '\0';
  }
  return cVar1;
}


