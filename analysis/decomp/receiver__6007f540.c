// 6007f540  receiver__6007f540  size=438 bytes
// src: receiver.cc
// --- callers ---
//   6007edf4 recording_pipeline__6007edf4
// --- callees ---
//   600decf8 FUN_600decf8
//   600c9de4 queue__600c9de4
//   6005c44c FUN_6005c44c
//   6013d378 thunk_EXT_FUN_0000b532
//   6013d3c8 thunk_EXT_FUN_00001680
//   6013cf40 thunk_EXT_FUN_00007d10
//   601017fc FUN_601017fc
//   600da478 FUN_600da478
//   6010177a FUN_6010177a
//   6010165c FUN_6010165c
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   60074ec8 FUN_60074ec8


/* src: receiver.cc */

int * receiver__6007f540(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined1 auStack_34 [4];
  undefined4 *local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  int local_24;
  
  thunk_EXT_FUN_0000b4c2(DAT_6007f6f8);
  piVar1 = DAT_6007f6fc;
  puVar7 = (undefined4 *)*param_2;
  FUN_600da478(auStack_34,param_2 + 1);
  puVar8 = (undefined4 *)*piVar1;
  local_28 = puVar7;
  if (puVar8 == (undefined4 *)0x0) {
    local_30 = puVar8;
    local_2c = puVar8;
    puVar7 = (undefined4 *)thunk_EXT_FUN_0000b532(0x9dc);
    FUN_600da478(&local_24,auStack_34);
    uVar2 = DAT_6007f704;
    puVar7[0x15] = 0;
    *puVar7 = uVar2;
    FUN_601017fc(puVar7 + 1);
    uVar2 = DAT_6007f708;
    puVar7[0x16] = 0;
    puVar7[0x17] = 0;
    *puVar7 = uVar2;
    uVar5 = queue__600c9de4(5,1,puVar7 + 0x2d,puVar7 + 0x18,0);
    uVar2 = DAT_6007f70c;
    puVar7[0x2c] = uVar5;
    *puVar7 = uVar2;
    puVar7[0x266] = 0;
    puVar7[0x62] = puVar7 + 100;
    *(undefined1 *)(puVar7 + 0x267) = 1;
    puVar7[99] = 0x200;
    uVar2 = DAT_6007f710;
    puVar7[0x268] = 0;
    puVar7[0x264] = uVar2;
    uVar2 = DAT_6007f714;
    puVar7[0x269] = 0;
    puVar7[0x265] = uVar2;
    puVar7[0x26a] = 0;
    puVar7[0x271] = puVar7 + 0x26d;
    puVar7[0x26b] = 0;
    puVar7[0x272] = 2;
    *(undefined1 *)(puVar7 + 0x26c) = 0;
    puVar7[0x275] = local_28;
    puVar7[0x26f] = 0;
    puVar7[0x270] = 0;
    FUN_600da478(puVar7 + 0x276,&local_24);
    puVar7[0x17] = puVar7 + 0x2f;
    iVar3 = DAT_6007f718;
    puVar7[0x26d] = DAT_6007f718;
    puVar7[0x26e] = iVar3 + 0x780;
    thunk_EXT_FUN_00001680(&local_24);
    local_28 = puVar8;
    puVar6 = (undefined4 *)thunk_EXT_FUN_0000b532(0x14);
    uVar2 = DAT_6007f71c;
    puVar6[4] = puVar7;
    *puVar6 = uVar2;
    local_28 = local_2c;
    puVar6[1] = 1;
    puVar6[2] = 1;
    local_30 = puVar7;
    local_2c = puVar6;
    thunk_EXT_FUN_00001680(&local_28);
    local_28 = (undefined4 *)*piVar1;
    *piVar1 = (int)local_30;
    local_24 = piVar1[1];
    piVar1[1] = (int)local_2c;
    local_30 = puVar8;
    local_2c = puVar8;
    thunk_EXT_FUN_00001680(&local_24);
    thunk_EXT_FUN_00001680(&local_2c);
    if ((*piVar1 != 0) && (cVar4 = FUN_6010177a(*piVar1,DAT_6007f720,0x1b), cVar4 != '\0')) {
      FUN_6010165c(0x28,DAT_6007f728,0x29,DAT_6007f724);
      FUN_600decf8(piVar1);
    }
  }
  else {
    FUN_600da478(&local_24,auStack_34);
    iVar3 = local_24;
    puVar8[0x275] = local_28;
    if (local_24 != puVar8[0x276]) {
      if (local_24 != 0) {
        FUN_60074ec8(local_24);
      }
      if (puVar8[0x276] != 0) {
        FUN_6005c44c();
      }
      puVar8[0x276] = iVar3;
    }
    thunk_EXT_FUN_00001680(&local_24);
  }
  uVar2 = DAT_6007f700;
  *param_1 = *piVar1;
  FUN_600da478(param_1 + 1,uVar2);
  thunk_EXT_FUN_00001680(auStack_34);
  thunk_EXT_FUN_00007d10(DAT_6007f6f8);
  return param_1;
}


