// 6006ad00  gatt_server__6006ad00  size=256 bytes
// src: gatt_server.cc
// --- callers ---
//   60069b20 adapter__60069b20
// --- callees ---
//   6006ac40 FUN_6006ac40
//   600d8bea FUN_600d8bea
//   6006acb8 FUN_6006acb8
//   600d3b3a FUN_600d3b3a
//   600d37ac FUN_600d37ac
//   600d8ac6 FUN_600d8ac6
//   600d37b8 FUN_600d37b8
//   600d3b24 FUN_600d3b24
//   6006a448 FUN_6006a448
//   600d8b9e FUN_600d8b9e
//   6010165c FUN_6010165c


/* src: gatt_server.cc */

void gatt_server__6006ad00(int param_1,undefined4 param_2,undefined2 *param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 auStack_dc [2];
  undefined2 local_da;
  undefined1 auStack_d8 [20];
  undefined1 auStack_c4 [20];
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [148];
  
  iVar2 = FUN_6006acb8(param_1 + 0xb10);
  uVar1 = DAT_6006ae00;
  if (iVar2 == 0) {
    piVar3 = (int *)FUN_600d8b9e(param_1 + 0x28,param_2);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 4))(piVar3,param_3,param_4);
      return;
    }
    local_b0 = DAT_6006ae00;
    local_ac = 0xbe;
    FUN_600d3b3a(auStack_a8);
    FUN_600d37ac(auStack_a8,DAT_6006ae1c);
    FUN_600d8ac6(auStack_a8,param_2);
    FUN_600d37b8(&local_b0);
    return;
  }
  FUN_6006ac40(auStack_dc,param_1 + 0xb10,param_2);
  local_b0 = uVar1;
  local_ac = 0x9a;
  FUN_600d3b3a(auStack_a8);
  FUN_600d37ac(auStack_a8,DAT_6006ae04);
  FUN_600d8ac6(auStack_a8,param_2);
  FUN_600d37ac(auStack_a8,DAT_6006ae08);
  FUN_600d8bea(auStack_a8,auStack_d8);
  FUN_600d37ac(auStack_a8,DAT_6006ae0c);
  FUN_600d8bea(auStack_a8,auStack_c4);
  FUN_600d3b24(&local_b0);
  piVar3 = (int *)FUN_600d8b9e(param_1 + 0x28,local_da);
  if (piVar3 == (int *)0x0) {
    uVar4 = 0xa3;
    uVar5 = DAT_6006ae10;
  }
  else {
    iVar2 = FUN_6006a448(auStack_c4,DAT_6006ae14);
    if (iVar2 == 0) {
      (**(code **)(*piVar3 + 0x10))(piVar3,auStack_c4,param_3,param_4);
      return;
    }
    if (param_4 == 2) {
      (**(code **)(*piVar3 + 8))(piVar3,*param_3);
      return;
    }
    uVar4 = 0xaa;
    uVar5 = DAT_6006ae18;
  }
  FUN_6010165c(0x28,uVar1,uVar4,uVar5);
  return;
}


