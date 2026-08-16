// 6008318c  remote_device_db__6008318c  size=638 bytes
// src: remote_device_db.cc
// --- callers ---
//   6006d6b0 FUN_6006d6b0
//   6008343c remote_device_db__6008343c
// --- callees ---
//   6013d2a0 thunk_EXT_FUN_00007a2c
//   60082b08 FUN_60082b08
//   6013d3c8 thunk_EXT_FUN_00001680
//   60082aac FUN_60082aac
//   6013cf80 thunk_EXT_FUN_0000714c
//   6010165c FUN_6010165c
//   6013d378 thunk_EXT_FUN_0000b532
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600dfc68 FUN_600dfc68
//   600da48a FUN_600da48a


/* src: remote_device_db.cc */

void remote_device_db__6008318c(void)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int local_30;
  undefined4 *local_2c;
  int local_28;
  undefined4 local_24 [2];
  
  piVar1 = DAT_60083414;
  FUN_6010165c(0x14,DAT_60083410,0x152,DAT_6008340c);
  thunk_EXT_FUN_00007a2c(piVar1[2],3,0,0,10);
  local_28 = 0;
  *piVar1 = 0;
  local_24[0] = 0;
  FUN_600da48a(piVar1 + 1,local_24);
  thunk_EXT_FUN_00001680(local_24);
  FUN_60082aac(&local_30);
  local_2c = (undefined4 *)0x0;
  local_28 = local_30;
  local_24[0] = 0;
  if (local_30 != 0) {
    local_2c = (undefined4 *)thunk_EXT_FUN_0000b532(0x10);
    iVar9 = local_30;
    local_30 = 0;
    local_2c[3] = iVar9;
    local_2c[1] = 1;
    local_2c[2] = 1;
    *local_2c = DAT_60083418;
  }
  FUN_600da48a(local_24,&local_2c);
  thunk_EXT_FUN_00001680(&local_2c);
  FUN_600dfc68(&local_30);
  iVar9 = local_28;
  if (local_28 == 0) {
    FUN_6010165c(0x1e,DAT_60083410,0x15f,DAT_6008341c);
  }
  else {
    iVar10 = 0;
    puVar8 = DAT_60083420 + 0x230;
    puVar3 = DAT_60083420;
    do {
      if (*(char *)((int)puVar3 + -1) != '\0') {
        iVar10 = iVar10 + 1;
        iVar11 = *(int *)(local_28 + 0x804);
        iVar5 = *(int *)(*(int *)(local_28 + 0x800) + 0x10) * 0x9d;
        *(undefined4 *)(iVar11 + iVar5) = *puVar3;
        iVar11 = iVar11 + iVar5;
        *(undefined2 *)(iVar11 + 4) = *(undefined2 *)(puVar3 + 1);
        *(undefined4 *)(iVar11 + 6) = *(undefined4 *)((int)puVar3 + 0x7f);
        *(undefined1 *)(iVar11 + 10) = *(undefined1 *)((int)puVar3 + 0x83);
        *(undefined1 *)(iVar11 + 0xb) = *(undefined1 *)(puVar3 + 0x21);
        *(undefined1 *)(iVar11 + 0xc) = *(undefined1 *)((int)puVar3 + 0x85);
        *(undefined1 *)(iVar11 + 0xd) = *(undefined1 *)((int)puVar3 + 0x86);
        puVar6 = (undefined4 *)((int)puVar3 + 0x87);
        puVar12 = (undefined4 *)(iVar11 + 0xe);
        do {
          puVar7 = puVar6 + 1;
          *puVar12 = *puVar6;
          puVar6 = puVar7;
          puVar12 = puVar12 + 1;
        } while (puVar7 != (undefined4 *)((int)puVar3 + 0xa3));
        puVar6 = (undefined4 *)(iVar11 + 0x2a);
        do {
          puVar12 = puVar7 + 1;
          *puVar6 = *puVar7;
          puVar7 = puVar12;
          puVar6 = puVar6 + 1;
        } while (puVar12 != (undefined4 *)((int)puVar3 + 0xbb));
        puVar6 = (undefined4 *)(iVar11 + 0x42);
        do {
          puVar13 = puVar6;
          puVar7 = puVar12;
          puVar12 = puVar7 + 1;
          *puVar13 = *puVar7;
          puVar6 = puVar13 + 1;
        } while (puVar12 != (undefined4 *)((int)puVar3 + 0xcf));
        *(undefined2 *)(puVar13 + 1) = *(undefined2 *)puVar12;
        *(undefined1 *)((int)puVar13 + 6) = *(undefined1 *)((int)puVar7 + 6);
        puVar6 = (undefined4 *)((int)puVar3 + 0xd3);
        puVar12 = (undefined4 *)(iVar11 + 0x59);
        do {
          puVar7 = puVar6 + 1;
          *puVar12 = *puVar6;
          puVar6 = puVar7;
          puVar12 = puVar12 + 1;
        } while (puVar7 != (undefined4 *)((int)puVar3 + 0xe7));
        puVar6 = (undefined4 *)(iVar11 + 0x6d);
        do {
          puVar12 = puVar7 + 1;
          *puVar6 = *puVar7;
          puVar7 = puVar12;
          puVar6 = puVar6 + 1;
        } while (puVar12 != (undefined4 *)((int)puVar3 + 0xff));
        puVar6 = (undefined4 *)(iVar11 + 0x85);
        do {
          puVar13 = puVar6;
          puVar7 = puVar12;
          puVar12 = puVar7 + 1;
          *puVar13 = *puVar7;
          puVar6 = puVar13 + 1;
        } while (puVar12 != (undefined4 *)((int)puVar3 + 0x113));
        *(undefined2 *)(puVar13 + 1) = *(undefined2 *)puVar12;
        *(undefined1 *)((int)puVar13 + 6) = *(undefined1 *)((int)puVar7 + 6);
        *(undefined1 *)(iVar11 + 0x9c) = *(undefined1 *)((int)puVar3 + 0x116);
        *(int *)(*(int *)(local_28 + 0x800) + 0x10) =
             *(int *)(*(int *)(local_28 + 0x800) + 0x10) + 1;
      }
      puVar3 = puVar3 + 0x46;
    } while (puVar8 != puVar3);
    thunk_EXT_FUN_0000b5ba
              (*(int *)(*(int *)(local_28 + 0x800) + 0x10) * 0x9d + *(int *)(local_28 + 0x804),0,
               0x9d);
    iVar11 = *(int *)(iVar9 + 0x804);
    iVar5 = *(int *)(*(int *)(iVar9 + 0x800) + 0x10) * 0x9d;
    *(undefined4 *)(iVar11 + iVar5) = 0;
    puVar2 = DAT_60083424;
    iVar11 = iVar11 + iVar5;
    *(undefined2 *)(iVar11 + 4) = 0;
    *(undefined1 *)(iVar11 + 6) = *puVar2;
    puVar3 = (undefined4 *)(iVar11 + 7);
    puVar8 = (undefined4 *)(puVar2 + 1);
    do {
      puVar6 = puVar8 + 1;
      *puVar3 = *puVar8;
      puVar3 = puVar3 + 1;
      puVar8 = puVar6;
    } while (puVar6 != (undefined4 *)(puVar2 + 0x11));
    puVar6 = DAT_60083428 + 4;
    puVar3 = (undefined4 *)(iVar11 + 0x17);
    puVar8 = DAT_60083428;
    do {
      puVar12 = puVar8 + 1;
      *puVar3 = *puVar8;
      puVar3 = puVar3 + 1;
      puVar8 = puVar12;
    } while (puVar12 != puVar6);
    puVar6 = DAT_6008342c + 4;
    puVar3 = (undefined4 *)(iVar11 + 0x27);
    puVar8 = DAT_6008342c;
    do {
      puVar12 = puVar8 + 1;
      *puVar3 = *puVar8;
      puVar3 = puVar3 + 1;
      puVar8 = puVar12;
    } while (puVar12 != puVar6);
    puVar6 = DAT_60083430 + 4;
    puVar3 = DAT_60083430;
    puVar8 = (undefined4 *)(iVar11 + 0x37);
    do {
      puVar12 = puVar3 + 1;
      *puVar8 = *puVar3;
      uVar4 = DAT_60083410;
      puVar3 = puVar12;
      puVar8 = puVar8 + 1;
    } while (puVar12 != puVar6);
    *(int *)(*(int *)(iVar9 + 0x800) + 0x10) = *(int *)(*(int *)(iVar9 + 0x800) + 0x10) + 1;
    FUN_6010165c(0x14,uVar4,0x171,DAT_60083434,iVar10);
    uVar4 = DAT_60083438;
    *piVar1 = local_28;
    FUN_600da48a(uVar4,local_24);
    iVar9 = piVar1[2];
    uVar4 = thunk_EXT_FUN_0000714c();
    thunk_EXT_FUN_00007a2c(iVar9,1,uVar4,0,10);
    FUN_60082b08(0 < iVar10);
  }
  thunk_EXT_FUN_00001680(local_24);
  return;
}


