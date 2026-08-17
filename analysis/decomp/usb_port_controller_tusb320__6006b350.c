// 6006b350  usb_port_controller_tusb320__6006b350  size=132 bytes
// src: usb_port_controller_tusb320.cc
// --- callers ---
//   6006b3e8 usb_port_controller_tusb320__6006b3e8
// --- callees ---
//   600d8e6c FUN_600d8e6c
//   600d37ac FUN_600d37ac
//   600d8dd0 FUN_600d8dd0
//   60051120 FUN_60051120
//   600d37b8 FUN_600d37b8


/* src: usb_port_controller_tusb320.cc */

undefined1 usb_port_controller_tusb320__6006b350(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  char local_b5;
  undefined1 auStack_b4 [8];
  undefined1 auStack_ac [144];
  undefined1 local_1c;
  
  iVar1 = DAT_6006b3d4;
  uVar3 = 0;
  do {
    cVar2 = FUN_600d8e6c(param_1,uVar3 & 0xff,&local_b5,0);
    if (cVar2 != '\0') {
      FUN_60051120(auStack_b4,DAT_6006b3d8,0xb4);
      FUN_600d37ac(auStack_ac,DAT_6006b3dc);
LAB_6006b37e:
      FUN_600d37b8(auStack_b4);
      return local_1c;
    }
    cVar2 = *(char *)(uVar3 + iVar1);
    if (local_b5 != cVar2) {
      FUN_60051120(auStack_b4,DAT_6006b3d8,0xb6,0xd);
      FUN_600d37ac(auStack_ac,DAT_6006b3e0);
      FUN_600d8dd0(auStack_ac,cVar2);
      FUN_600d37ac(auStack_ac,DAT_6006b3e4);
      FUN_600d8dd0(auStack_ac,local_b5);
      goto LAB_6006b37e;
    }
    uVar3 = uVar3 + 1;
    if (uVar3 == 8) {
      return 0;
    }
  } while( true );
}


