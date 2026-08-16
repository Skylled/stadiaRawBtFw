// 6005b794  application_state__6005b794  size=168 bytes
// src: application_state.cc
// --- callers ---
//   6005b850 application_state__6005b850
// --- callees ---
//   6007f8e4 pattern_player__6007f8e4
//   601016f0 FUN_601016f0
//   600d37ac FUN_600d37ac
//   6005ac84 FUN_6005ac84
//   600d4036 FUN_600d4036
//   6007f870 FUN_6007f870
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   6013cf40 thunk_EXT_FUN_00007d10
//   600670f4 gotham_patterns__600670f4
//   600d3b3a FUN_600d3b3a


/* src: application_state.cc */

void application_state__6005b794(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 auStack_98 [144];
  
  uVar1 = DAT_6005b848;
  switch(*(undefined4 *)(param_1 + 0x78)) {
  case 1:
    goto switchD_6005b7a2_caseD_1;
  case 2:
  case 7:
    uVar1 = FUN_6007f870();
    uVar2 = 0xe;
    break;
  case 3:
    uVar1 = FUN_6007f870();
    thunk_EXT_FUN_0000b4c2();
    pattern_player__6007f8e4(uVar1,6,0,0,DAT_6005b844,0);
    thunk_EXT_FUN_00007d10(uVar1);
    return;
  case 4:
    uVar1 = FUN_6007f870();
    uVar2 = 0x11;
    break;
  case 5:
    uVar1 = FUN_6007f870();
    uVar2 = 0x1e;
    break;
  case 6:
    uVar1 = FUN_6007f870();
    uVar2 = 0x15;
    break;
  default:
    FUN_600d3b3a(auStack_98);
    FUN_600d37ac(auStack_98,DAT_6005b84c);
    FUN_600d4036(auStack_98,param_1 + 0x78);
    FUN_601016f0(0x1e,uVar1,0x1b5,auStack_98);
    goto switchD_6005b7a2_caseD_1;
  }
  uVar2 = gotham_patterns__600670f4(uVar2);
  FUN_6005ac84(uVar1,6,uVar2);
switchD_6005b7a2_caseD_1:
  return;
}


