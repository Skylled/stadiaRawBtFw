// 600cbdd4  init__600cbdd4  size=22 bytes
// src: init.cc
// --- callers ---
//   60051168 main__60051168
// --- callees ---
//   600ca4ac tasks__600ca4ac
//   60058574 system_tasks__60058574
//   601016a2 FUN_601016a2


/* src: init.cc */

void init__600cbdd4(void)

{
  system_tasks__60058574();
  tasks__600ca4ac();
  FUN_601016a2(DAT_600cbdf0,0x38,DAT_600cbdec);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


