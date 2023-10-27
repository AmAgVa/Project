#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TLegend.h>

void histogram() {
    // Create a canvas to display the combined histograms
    TCanvas *c1 = new TCanvas("c1", "Combined Histograms", 800, 600);

    // Create histograms
    TH1F *coldestDaysHist = new TH1F("coldestHist", "Coldest Days Histogram", 300, 1, 366);
    TH1F *warmestDaysHist = new TH1F("warmestHist", "Warmest Days Histogram", 300, 1, 366);

    // Set fill colors for the histograms
    coldestDaysHist->SetFillColor(kBlue);
    warmestDaysHist->SetFillColor(kRed);

    // Read data from the input files and fill the histograms
    std::ifstream coldestDataFile("coldest_days.txt");
    std::ifstream warmestDataFile("warmest_days.txt");
    int value;

    while (coldestDataFile >> value) {
        coldestDaysHist->Fill(value);
    }

    while (warmestDataFile >> value) {
        warmestDaysHist->Fill(value);
    }

    // Set axis labels
    coldestDaysHist->GetXaxis()->SetTitle("Day of Year");
    coldestDaysHist->GetYaxis()->SetTitle("Entries");

    // Set the maximum value on the Y-axis to 12
    coldestDaysHist->GetYaxis()->SetRangeUser(0, 12);
    warmestDaysHist->GetYaxis()->SetRangeUser(0, 12);

    // Draw the histograms on the same canvas with "bar" option to fill the histograms
    coldestDaysHist->Draw("bar");
    warmestDaysHist->Draw("bars same");

    // Create a legend
    TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend->AddEntry(coldestDaysHist, "Coldest Days", "f");
    legend->AddEntry(warmestDaysHist, "Warmest Days", "f");
    legend->Draw();

    // Save the combined canvas as an image
    c1->SaveAs("combined_histogram.png");
}