// 600d17ae  FUN_600d17ae  size=248 bytes
// --- callers ---
//   60055bd8 FUN_60055bd8
// --- callees ---
//   600d3256 FUN_600d3256
//   600d3244 FUN_600d3244


undefined4 FUN_600d17ae(undefined4 *param_1)

{
  ushort uVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  undefined4 local_30;
  undefined2 local_2c;
  ushort local_2a;
  undefined1 local_28;
  byte local_27;
  undefined2 local_26;
  undefined1 local_24;
  
  if (param_1[10] != 0) {
    FUN_600d3256(*param_1);
    param_1[10] = 0;
  }
  if (param_1[0xb] != 0) {
    FUN_600d3256(*param_1);
    param_1[0xb] = 0;
  }
  bVar6 = 0;
  iVar5 = param_1[2];
  do {
    if ((uint)*(byte *)(iVar5 + 0x3c) <= (uint)bVar6) {
      return 0;
    }
    iVar4 = *(int *)(iVar5 + (uint)bVar6 * 0xc);
    local_27 = *(byte *)(iVar4 + 2);
    bVar2 = *(byte *)(iVar4 + 3) & 3;
    if ((int)((uint)local_27 << 0x18) < 0) {
      if (bVar2 == 1) {
        local_30 = param_1[1];
        local_26 = 0x101;
        local_28 = *(undefined1 *)(iVar4 + 6);
        uVar1 = *(ushort *)(iVar4 + 4);
        *(byte *)((int)param_1 + 0x65) = local_27 & 0xf;
        puVar3 = param_1 + 10;
        local_2a = (ushort)(((uint)uVar1 << 0x15) >> 0x15);
        *(ushort *)(param_1 + 0x18) = local_2a;
LAB_600d184e:
        local_27 = local_27 & 0xf;
        local_24 = 0;
        local_2c = 3000;
        iVar4 = FUN_600d3244(*param_1,puVar3,&local_30);
        if (iVar4 != 0) {
          return 1;
        }
      }
    }
    else if (bVar2 == 1) {
      local_30 = param_1[1];
      local_26 = 0x100;
      local_28 = *(undefined1 *)(iVar4 + 6);
      uVar1 = *(ushort *)(iVar4 + 4);
      *(byte *)((int)param_1 + 0x65) = local_27 & 0xf;
      puVar3 = param_1 + 0xb;
      local_2a = (ushort)(((uint)uVar1 << 0x15) >> 0x15);
      *(ushort *)((int)param_1 + 0x62) = local_2a;
      goto LAB_600d184e;
    }
    bVar6 = bVar6 + 1;
  } while( true );
}


