// 600f9df0  FUN_600f9df0  size=552 bytes
// --- callers ---
//   600b6d30 FUN_600b6d30
//   600b6900 FUN_600b6900
// --- callees ---
//   600fa064 FUN_600fa064
//   600f87b8 FUN_600f87b8


undefined4 FUN_600f9df0(int param_1,undefined2 *param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  bVar1 = true;
  bVar3 = true;
  bVar2 = true;
  if (*(char *)(param_2 + 0x12) == '\0') {
    *(undefined1 *)(param_2 + 0x13) = 0;
  }
  if (*(char *)(param_2 + 1) == '\0') {
    if (*(char *)(param_1 + 0x5a) != '\0') {
      *(undefined1 *)(param_2 + 1) = 1;
      param_2[2] = *(undefined2 *)(param_1 + 0x5c);
    }
  }
  else if ((ushort)param_2[2] < 0x30) {
    param_2[2] = 0x30;
    bVar1 = false;
  }
  else {
    if ((*(char *)(param_2 + 0x12) == '\0') && (0x248 < (ushort)param_2[2])) {
      param_2[2] = 0x248;
    }
    *(undefined2 *)(param_1 + 0x5c) = param_2[2];
    *(undefined1 *)(param_1 + 0x5a) = 1;
    *(ushort *)(param_1 + 0x54) = *(ushort *)(param_1 + 0x54) | 1;
  }
  if (*(char *)(param_2 + 0x10) == '\0') {
    if (*(char *)(param_1 + 0x78) != '\0') {
      *(undefined1 *)(param_2 + 0x10) = 1;
      param_2[0x11] = *(undefined2 *)(param_1 + 0x7a);
    }
  }
  else if (param_2[0x11] == 0) {
    param_2[0x11] = 0xffff;
    bVar2 = false;
  }
  else {
    *(undefined1 *)(param_1 + 0x78) = 1;
    *(undefined2 *)(param_1 + 0x7a) = param_2[0x11];
    *(ushort *)(param_1 + 0x54) = *(ushort *)(param_1 + 0x54) | 4;
  }
  if (*(char *)(param_2 + 3) == '\0') {
    if (*(char *)(param_1 + 0x5e) != '\0') {
      *(undefined1 *)(param_2 + 3) = 1;
      uVar5 = *(undefined4 *)(param_1 + 100);
      uVar6 = *(undefined4 *)(param_1 + 0x68);
      uVar7 = *(undefined4 *)(param_1 + 0x6c);
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0x60);
      *(undefined4 *)(param_2 + 6) = uVar5;
      *(undefined4 *)(param_2 + 8) = uVar6;
      *(undefined4 *)(param_2 + 10) = uVar7;
      uVar5 = *(undefined4 *)(param_1 + 0x74);
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0x70);
      *(undefined4 *)(param_2 + 0xe) = uVar5;
    }
  }
  else if (*(byte *)((int)param_2 + 9) < 3) {
    uVar5 = *(undefined4 *)(param_2 + 6);
    uVar6 = *(undefined4 *)(param_2 + 8);
    uVar7 = *(undefined4 *)(param_2 + 10);
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)(param_1 + 100) = uVar5;
    *(undefined4 *)(param_1 + 0x68) = uVar6;
    *(undefined4 *)(param_1 + 0x6c) = uVar7;
    uVar5 = *(undefined4 *)(param_2 + 0xe);
    *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)(param_1 + 0x74) = uVar5;
    *(undefined1 *)(param_1 + 0x5e) = 1;
    *(ushort *)(param_1 + 0x54) = *(ushort *)(param_1 + 0x54) | 2;
  }
  else {
    *(undefined1 *)((int)param_2 + 9) = 1;
    bVar3 = false;
  }
  cVar4 = FUN_600f87b8(param_1,param_2);
  if (cVar4 == '\x02') {
    *param_2 = 2;
    *(undefined1 *)(param_2 + 0x10) = 0;
    *(undefined1 *)(param_2 + 3) = *(undefined1 *)(param_2 + 0x10);
    *(undefined1 *)(param_2 + 1) = *(undefined1 *)(param_2 + 3);
    uVar5 = 2;
  }
  else if ((((bVar1) && (bVar2)) && (bVar3)) && (cVar4 == '\x01')) {
    FUN_600fa064(param_1);
    uVar5 = 1;
  }
  else {
    *param_2 = 1;
    if (bVar1) {
      *(undefined1 *)(param_2 + 1) = 0;
    }
    if (bVar2) {
      *(undefined1 *)(param_2 + 0x10) = 0;
    }
    if (bVar3) {
      *(undefined1 *)(param_2 + 3) = 0;
    }
    if (cVar4 == '\x01') {
      *(undefined1 *)(param_2 + 0x12) = 0;
    }
    uVar5 = 0;
  }
  return uVar5;
}


