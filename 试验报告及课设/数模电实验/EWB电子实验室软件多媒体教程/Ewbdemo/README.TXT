    ----------------------------------------------------
    Welcome to the Electronics Workbench Design Solution
    ----------------------------------------------------

    The Design Solution includes: Electronics Workbench + EWB Layout.
    Each product can be purchased individually or purchased together
    as a suite. Electronics Workbench Version 5 has been updated to
    tightly integrate with Electronics Workbench Layout. Current
    Electronics Workbench Version 5 users must enter their EWB serial
    number during the Layout installation process to replace their
    EWB with the Version that has been modified for optimal
    integration with Layout.

    ===================================================
    Electronics Workbench Edition Documentation Updates
    ===================================================

    1. Release Notes

    The Release Notes contain important information that was
    received too late to be included in the written documentation.

    They can be found in the online help. To view the release
    notes, start Electronics Workbench and choose Release Notes
    from the Help menu.

    2. Further Information Not Included in On-line Help

    The following information has not been included in the online Help.

    i) Parser Errors Tab

    A new tab has been added to the Analysis Graphs Window, called
    "Parser Errors". The tab appears only if errors occur during
    the parsing of a subcircuit netlist model. (Note: Parsing
    occurs after you start a simulation or analysis.)

    Most of the errors appearing in this list are only warnings.
    They simply notify the user of syntax in a netlist which is
    unsupported by Electronics Workbench.


    ii) Electronics Workbench User's Guide Corrections


    Page 5-5 - The circuit under Step 1 shows the first connection
    of the word generator connected to connector "S" and the second
    connection of the word generator connected to connector "R".
    This is reversed. The first connection of the word generator
    should be connected to connector "R" and the second to
    connector "S".

    The procedure for setting the logic analyzer under Step 1 is no
    longer correct as the logic analyzer was revised after the
    printing of the User's Guide and Technical Reference.

    The new procedure for setting the Logic Analyzer is as follows:

    1.  Set the frequency of the word generator to 1 MHz.
    2.  On the logic analyzer, set the clocks per division to 1.
    3.  Click on the set button in the clock box and ensure the
        following:
        -  Clock edge "negative"
        -  Clock mode "internal"
        -  Set internal clock rate to "1 MHz"
        -  Clock qualifier "x"
        -  Logic analyzer "Pre-trigger samples 100"
                          "Post-trigger samples 1000"
                          "Threshold voltage (V) 3.5"
    4.  Make sure the Current address on the word generator is 0000.
    5.  Click the Cycle button on the word generator.

    iii) EWB Technical Reference Corrections

    PAGE 14-22 - The picture of the opened logic analyzer is
    incorrect. Since the manual was printed, the Time Base feature
    has been removed and replaced with a Clocks per division
    feature.

    The "Time base" setting was used to set the logic analyzer's
    display in units of seconds/division. The "Clocks per division"
    setting is used to set the traces in units of clocks/division.
    The number of clocks refers to the number of samples of the
    data from the input terminals which have been taken.

    Page 14-23 - The third paragraph discusses how to specify the
    number of samples stored before and after triggering. The user
    can also specify the number of samples by selecting the set
    button in the clock box of the logic analyzer and making the
    appropriate changes.

    ============================================================
    Electronics Workbench Layout Documentation Updates
    ============================================================

    1. Reference IDs

    When using Electronics Workbench and EWB Layout together, it
    is important that reference IDs consist of the letters A-Z
    (upper case) and numbers 0-9 only. Lower case or accented
    characters may cause problems in backannotation or autorouting.

    2. Drive mapping on Windows NT 4

    If you are running EWB Layout on Windows NT 4, the external
    autorouter will not start up if your drive name begins
    with "\\". You will need to remap your drive.

    2. Uninstalling on Windows NT 4

    If you are uninstalling Electronics Workbench and EWB Layout on
    Windows NT 4, you may get an error message referring to a missing .DLL.
    Please ignore this message. The uninstall will proceed normally.

    ================================================================

    Electronics Workbench is a registered trademark of Interactive
    Image Technologies Ltd.

    Copyright (c) Interactive Image Technologies Ltd., 1996.


