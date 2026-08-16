// 6006ae20  gatt_server__6006ae20  size=492 bytes
// src: gatt_server.cc
// --- callers ---
//   60069a38 adapter__60069a38
// --- callees ---
//   6006ac40 FUN_6006ac40
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600d3b3a FUN_600d3b3a
//   600d37ac FUN_600d37ac
//   600d37b8 FUN_600d37b8
//   6006a448 FUN_6006a448
//   600d8b9e FUN_600d8b9e
//   601016f0 FUN_601016f0
//   6010165c FUN_6010165c
//   60095904 FUN_60095904
//   600d8bea FUN_600d8bea
//   6006acb8 FUN_6006acb8
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600d8ac6 FUN_600d8ac6
//   6006a734 gatt_server__6006a734


/* src: gatt_server.cc */

void gatt_server__6006ae20
               (int param_1,undefined4 param_2,undefined4 param_3,uint param_4,ushort param_5,
               char param_6)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 local_358;
  undefined4 uStack_354;
  undefined1 auStack_350 [2];
  undefined2 local_34e;
  undefined1 auStack_34c [20];
  undefined1 auStack_338 [20];
  undefined4 local_324;
  undefined4 local_320;
  undefined1 auStack_31c [144];
  undefined2 local_28c;
  undefined2 local_28a;
  short local_288;
  short local_286;
  undefined1 local_284;
  undefined1 auStack_283 [607];
  
  thunk_EXT_FUN_0000b5ba(&local_28c,0,0x262);
  iVar3 = FUN_6006acb8(param_1 + 0xb10,param_4);
  uVar2 = (undefined2)param_4;
  if (iVar3 == 0) {
    iVar3 = FUN_600d8b9e(param_1 + 0x28,param_4);
    if (iVar3 != 0) {
      if ((param_6 == '\0') || (*(ushort *)(param_1 + 0x1718) != param_4)) {
        *(undefined2 *)(param_1 + 0x1718) = uVar2;
        *(undefined2 *)(param_1 + 0x171a) = 0;
        *(undefined1 *)(param_1 + 0x171c) = 0;
        *(undefined1 *)(param_1 + 0x1975) = 1;
        (**(code **)(iVar3 + 0x10))(*(undefined4 *)(iVar3 + 0x14));
      }
      goto LAB_6006af32;
    }
    local_324 = DAT_6006b020;
    local_320 = 0xf7;
    FUN_600d3b3a(auStack_31c);
    uVar6 = DAT_6006b028;
LAB_6006af7e:
    FUN_600d37ac(auStack_31c,uVar6);
    FUN_600d8ac6(auStack_31c,param_4);
    FUN_600d37b8(&local_324);
  }
  else {
    FUN_6006ac40(auStack_350,param_1 + 0xb10,param_4);
    uVar7 = DAT_6006b020;
    local_324 = DAT_6006b020;
    local_320 = 0xcd;
    FUN_600d3b3a(auStack_31c);
    FUN_600d37ac(auStack_31c,DAT_6006b00c);
    FUN_600d8ac6(auStack_31c,param_4);
    FUN_600d37ac(auStack_31c,DAT_6006b010);
    FUN_600d8bea(auStack_31c,auStack_34c);
    FUN_600d37ac(auStack_31c,DAT_6006b014);
    FUN_600d8bea(auStack_31c,auStack_338);
    FUN_601016f0(10,local_324,local_320,auStack_31c);
    piVar4 = (int *)FUN_600d8b9e(param_1 + 0x28,local_34e);
    uVar6 = DAT_6006b01c;
    if (piVar4 != (int *)0x0) {
      if ((param_6 == '\0') || (*(ushort *)(param_1 + 0x1718) != param_4)) {
        *(undefined2 *)(param_1 + 0x1718) = uVar2;
        *(undefined1 *)(param_1 + 0x1975) = 1;
        *(undefined2 *)(param_1 + 0x171a) = 0;
        *(undefined1 *)(param_1 + 0x171c) = 0;
        local_358 = 0;
        uStack_354 = 0;
        iVar3 = FUN_6006a448(auStack_338,uVar6);
        if (iVar3 == 0) {
          (*(code *)piVar4[6])(piVar4[7],auStack_338,&local_358);
          uVar6 = local_358;
          uVar7 = uStack_354;
        }
        else {
          local_324 = (**(code **)(*piVar4 + 0xc))(piVar4);
          local_320 = 2;
          uVar6 = local_324;
          uVar7 = 2;
        }
        gatt_server__6006a734(param_1 + 0x1718,uVar6,uVar7);
      }
LAB_6006af32:
      if (*(char *)(param_1 + 0x171c) != '\0') {
        uVar6 = 0;
        uVar1 = *(ushort *)(param_1 + 0x171a);
        local_28c = (undefined2)param_2;
        local_284 = 0;
        uVar5 = (uint)param_5;
        if ((uint)uVar1 <= (uint)param_5) {
          uVar5 = (uint)uVar1;
        }
        local_288 = (short)uVar5;
        local_286 = uVar1 - local_288;
        local_28a = uVar2;
        thunk_EXT_FUN_0000b572(auStack_283,uVar5 + param_1 + 0x171d);
        *(undefined2 *)(param_1 + 0x1718) = 0;
        *(undefined1 *)(param_1 + 0x1975) = 0;
        goto LAB_6006aece;
      }
      local_324 = DAT_6006b020;
      local_320 = 0x107;
      FUN_600d3b3a(auStack_31c);
      uVar6 = DAT_6006b024;
      goto LAB_6006af7e;
    }
    FUN_6010165c(0x28,uVar7,0xd6,DAT_6006b018);
  }
  uVar6 = 10;
LAB_6006aece:
  FUN_60095904(param_2,param_3,uVar6,&local_28c);
  return;
}


