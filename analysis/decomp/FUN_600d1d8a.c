// 600d1d8a  FUN_600d1d8a  size=236 bytes
// --- callers ---
//   60055d78 FUN_60055d78
// --- callees ---
//   600d3244 FUN_600d3244
//   600d3256 FUN_600d3256


undefined4 FUN_600d1d8a(undefined4 *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  undefined4 local_30;
  undefined2 local_2c;
  ushort local_2a;
  undefined1 local_28;
  byte local_27;
  undefined2 local_26;
  undefined1 local_24;
  
  if (param_1[4] != 0) {
    FUN_600d3256(*param_1);
    param_1[4] = 0;
  }
  if (param_1[5] != 0) {
    FUN_600d3256(*param_1);
    param_1[5] = 0;
  }
  bVar5 = 0;
  iVar4 = param_1[2];
  do {
    if ((uint)*(byte *)(iVar4 + 0x3c) <= (uint)bVar5) {
      return 0;
    }
    iVar3 = *(int *)(iVar4 + (uint)bVar5 * 0xc);
    local_27 = *(byte *)(iVar3 + 2);
    bVar1 = *(byte *)(iVar3 + 3) & 3;
    if ((int)((uint)local_27 << 0x18) < 0) {
      if (bVar1 == 3) {
        local_30 = param_1[1];
        local_26 = 0x301;
        puVar2 = param_1 + 4;
        local_28 = *(undefined1 *)(iVar3 + 6);
        local_2a = (ushort)(((uint)*(ushort *)(iVar3 + 4) << 0x15) >> 0x15);
        *(ushort *)(param_1 + 0xd) = local_2a;
LAB_600d1e24:
        local_27 = local_27 & 0xf;
        local_24 = 0;
        local_2c = 3000;
        iVar3 = FUN_600d3244(*param_1,puVar2,&local_30);
        if (iVar3 != 0) {
          return 1;
        }
      }
    }
    else if (bVar1 == 3) {
      local_26 = 0x300;
      local_30 = param_1[1];
      local_28 = *(undefined1 *)(iVar3 + 6);
      puVar2 = param_1 + 5;
      local_2a = (ushort)(((uint)*(ushort *)(iVar3 + 4) << 0x15) >> 0x15);
      *(ushort *)((int)param_1 + 0x36) = local_2a;
      goto LAB_600d1e24;
    }
    bVar5 = bVar5 + 1;
  } while( true );
}


