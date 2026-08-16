// 600ac014  FUN_600ac014  size=270 bytes
// --- callers ---
//   600ac438 FUN_600ac438
// --- callees ---
//   600f45a6 FUN_600f45a6
//   6009b77c FUN_6009b77c
//   600f42d8 FUN_600f42d8
//   600b00b4 FUN_600b00b4
//   6006dbac FUN_6006dbac
//   600f610e FUN_600f610e
//   6006ddd8 FUN_6006ddd8


undefined1 FUN_600ac014(int *param_1)

{
  ushort uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined1 *local_14;
  
  iVar3 = param_1[3];
  uVar1 = *(ushort *)(*param_1 + 0x1a);
  FUN_600f42d8(*param_1,1);
  puVar2 = (undefined1 *)FUN_6006dbac(*(short *)(iVar3 + 6) + 3,DAT_600ac124,0x29);
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 0xd2;
    puVar2[1] = (char)*(undefined2 *)(iVar3 + 2);
    puVar2[2] = (char)((ushort)*(undefined2 *)(iVar3 + 2) >> 8);
    local_14 = puVar2 + 3;
    for (iVar4 = 0; iVar4 < (int)(uint)*(ushort *)(iVar3 + 6); iVar4 = iVar4 + 1) {
      *local_14 = *(undefined1 *)(iVar3 + iVar4 + 9);
      local_14 = local_14 + 1;
    }
    if ((int)(uVar1 - 0xf) < (int)(uint)*(ushort *)(iVar3 + 6)) {
      *(ushort *)(iVar3 + 6) = uVar1 - 0xf;
    }
    iVar4 = FUN_6009b77c(*param_1 + 0xd,puVar2,*(short *)(iVar3 + 6) + 3,
                         iVar3 + 9 + (uint)*(ushort *)(iVar3 + 6));
    if (iVar4 == 0) {
      FUN_600b00b4(param_1,0x81,0);
    }
    else {
      *(short *)(iVar3 + 6) = *(short *)(iVar3 + 6) + 0xc;
      FUN_600f610e(*param_1,4);
      FUN_600f45a6(param_1,2);
    }
    FUN_6006ddd8(puVar2,DAT_600ac124,0x45);
  }
  return 0;
}


